#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &a, int k){
    vector<int> ans;
    deque<int> dq;
    int i=0;
    for(;i<k;i++){
        while(!dq.empty() and a[dq.back()] < a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    ans.push_back(a[dq.front()]);



    for(int i=k ; i<a.size();i++){
        if(!dq.empty() and dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() and a[dq.back()] < a[i] ){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }

    return ans;
}

int solve(){
    vector<int> a;
    a.push_back(20);
    a.push_back(2);
    a.push_back(-1);
    a.push_back(7);
    a.push_back(10);
    a.push_back(12);
    vector<int> ans(solution(a,2));

    for(int i:ans){
        cout << i << " ";
    }
}

int main(){
    solve();
}