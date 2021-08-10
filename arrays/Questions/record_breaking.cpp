#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)

int solve(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0;i<n;i++)cin >> a[i];

    int pm=a[0], ans=0;
    if(a[0]>a[1])ans++;

    for(int i=1;i<n-1;i++){
        if(pm<a[i-1])pm = a[i-1];
        if(a[i]>a[i+1] && a[i]>pm)ans++;        
    }
    cout << ans;

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