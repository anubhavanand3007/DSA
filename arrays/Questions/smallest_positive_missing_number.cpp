#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
int solve(){
    int n,k;
    cin >> n >>k;
    int a[n];
    f(i,n)cin >> a[i];
    
    int ai = 10^6;
    char s[ai];

    f(i,ai){
        s[i]='F';
    }


    f(i,n){
        s[a[i]]='T';
    }

    f(i,ai){
        if(s[i]=='F'){
            cout << i;
            break;
        }
    }
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