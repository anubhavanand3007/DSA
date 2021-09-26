#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)

int solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];

    int ai = 10^6;
    int s[ai] = {0};
    for(int i=0;i<ai;i++)s[i] = 0;;


    for(int i=0;i<n;i++){
        s[a[i]]++;
    }



    for(int i=0;i<ai;i++){
        if(s[i]>1){
            cout << i;
            break;
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    for(int test= 1; test<=t ; test++){

        cout << "Case #" << test << ": " ;
        solve();
        cout << "\n";
   }
    return 0;
}