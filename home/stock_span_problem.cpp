#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> a){
    stack<pair<int,int>> st;
    vector<int> ans;
    int n = a.size();
    ans.push_back(1);
    st.push({a[0],0});

    for(int i=1;i<n;i++){
        while(!st.empty() and st.top().first < a[i]){
            st.pop();
        }

        if(st.empty()){
            ans.push_back(i+1);
        }
        else{
            ans.push_back(i-st.top().second);
        }
        st.push({a[i],i});
    }

    return ans;

}

int main(){
    vector<int>  a = {100,80,60,70,60,75,85};
    vector<int> ans(solve(a));
    for(int i:ans){
        cout << i << " ";
    }
}