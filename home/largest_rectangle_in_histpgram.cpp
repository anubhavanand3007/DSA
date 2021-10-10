#include<bits/stdc++.h>
using namespace std;

/*
a = [1,2,3,4,5,6,2,5,10]
observation:
1. edge cases:
   i. when i=0 and a.size(): area will be a[i]*1;
   ii. when two seperate rectangles are formed left and right if a[i] == 0
2. fully contribution of a[i] values will be in a rectangle of a[i] height.
3. no contribution of a[i] value if the height>a[i].
4. partial contribution if height < a[i]

approach 1:
1. find all the rectangle possible and calculate max among them.
1. find nearest element to left and right of the current index that is less than current element
2. find the maximum of all the area formed with respect to each index (for every index we need to find max area possible formed via that index).

approach 2:
1. pushing element to the stack till the values in histogram array increases
2. pop values till the top of stack contain value lower than value on current index.
3. repeat this for both left and right limits.
3. find equivalent area by subtracting left and right limit of indivisual indexes.
*/

int solve(vector<int> a){
    vector<int> left, right;
    stack<int> st;

    for(int i=0;i<a.size();i++){
        if(!st.empty()){
            if(a[st.top()] < a[i]){
                st.push(i);
                left.push_back(st.top());
            }
            else{
                while(!st.empty() && a[st.top()] < a[i]){
                    st.pop();
                }
                st.push(i);
                left.push_back(i);
            }
        }
        else{
            st.push(i);
        }
    }

    for(int i=a.size();i>=0;i--){
        if(!st.empty()){
            if(a[st.top()] < a[i]){
                st.push(i);
                right.push_back(st.top());
            }
            else{
                while(!st.empty() && a[st.top()] < a[i]){
                    st.pop();
                }
                st.push(i);
                right.push_back(i);
            }
        }
        else{
            st.push(i);
        }
    }

    int maxi = abs(left[0] - right[0])*a[0];

    for(int i=0;i<a.size();i++){
        maxi = max(maxi,abs(left[i] - right[i])*a[i]);
    }

    return maxi;

}


int main(){
    vector<int> a = {2,1,5,6,2,3};
    for(int i:a){
        cout << i << " ";
    }
    cout << "\n";
    cout << solve(a);
}