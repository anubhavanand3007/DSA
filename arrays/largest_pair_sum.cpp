#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)

bool brute_force_approach(int a[],int n,int k){
    f(i,n){
        for(int j=i;j<n;j++){
            if(a[i]+a[j]==k){
                cout << true;
                return true;
            }
        }
    }
}

bool binary_search(int a[],int n, int k){
    sort(a,a+n);
    int low =0, high = n;
    f(i,n){
        if(high==low)return false;
        if(a[low]+a[high]==k){
            cout << true;
            return true;
        }
        else if(a[low]+a[high]>k)high--;
        else low++;
    }
}

int solve(){
    ;
}

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    f(i,n)cin >> a[i];

    brute_force_approach(a,n,k);
    binary_search(a,n,k);
    return 0;
}