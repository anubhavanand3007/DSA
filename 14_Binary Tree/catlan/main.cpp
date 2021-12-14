#include<bits/stdc++.h>
using namespace std;

int catlan(int n){
    if(n==1 || n==0) return 1;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += catlan(i)*catlan(n-1-i);
    }
    return sum;
}

int solve(){
    cout << catlan(4);
}
int main(){
    solve();
}