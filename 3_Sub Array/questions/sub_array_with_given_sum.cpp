#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)

int solve(){
    int n,k;
    cin >> n >> k;
    int a[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int curr=a[0];
    int ansi=0, ansj=0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(k==curr){
                ansi =i+1;
                ansj =j;
                break;
            }
            else if(k>curr)curr+=a[j];
        }
        curr=0;
    }

    cout << ansi << " " << ansj;
}

int main(){
    int t;
    cin >> t;
    for(int test= 1; test<=t ; test++){

        cout << "Case #" << test << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}