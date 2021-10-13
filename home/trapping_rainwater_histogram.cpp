#include<bits/stdc++.h>
using namespace std;

/*
obervations:
1. binary or unity cases: total water collected will be 0 --> no space left for storing water.
2. total water = sum of water above a single histogram block.
3. level of water on each block is mim(left_limit, right_limit) {limit: element greater than the value on index}

approach 1:
1. iterate through every element.
2. iterated left and right seperately for each element to find the right_limit and left_limit.
3. find level of water on each block by : level = min (right_limit,left_limit) - a[i]
4. sum of all water levels.
result: time complexity: O(n^2), space complexity: O(n).

approach 2:
1. iterate through every element(first from left to right).
2.  i. push 0 in stack initially
    ii. st.top() > a[i] --> left_limit.push_back(st.top())
    iii. st.top() <= a[i] --> left_limit.push_back(0)
3. do same method for right to left and find right_limit
4. water level on each block = min(left_limit[i] , right_element[i]) - a[i];
5.find sum of water level.
result: T.C. = O(n) and S.C. = O(n)
*/

int solve(vector<int> a){
    int left_limit[100], right_limit[100] ;
    int limit = 0;
    for(int i=0;i<a.size();i++){
        if (a[limit] < a[i] )limit = i;
        left_limit[i] = limit;
    }

    limit = a.size()-1;
    for(int i=a.size()-1;i>=0;i--){
        if (a[limit] < a[i] )limit = i;
        right_limit[i]= limit;
    }

    int sum = 0;
    for(int i=0;i<a.size();i++){
        sum += (abs(min( a[left_limit[i]], a[right_limit[i]] )) - a[i]);
    }
    return sum;
}

int main(){
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << solve(a);
}