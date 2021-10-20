#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)
int solve(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0;i<n;i++)cin >> a[i];

    int curr =2, ans=2, d;

    for(int i=0;i<n-2;i++){
        for(int j=i;j<n-2;j++){
            if(j==i)d = a[j]-a[j+1];
            
            if(d==a[j+1]-a[j+2])curr++;
            else break;

        }
        ans=max(curr,ans);
        curr=2;
    }
    cout << ans;
}

int main(){
    int t;
    cin >> t;
    for(int test= 1; test<=t ; test++){
    

        cout << "Case #" << test << ": " ;
        solve();
        cout << " ";
    }
    return 0;
}