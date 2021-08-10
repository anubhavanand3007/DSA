#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)

int solve(){
    int n;
    cin >> n;
    int a[n];
    int ans[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int max_element = a[0];
    for(int i=0;i<n;i++){
        if(max_element>a[i])ans[i]=max_element;
        else{
            max_element=a[i];
            ans[i]=max_element;
        }
    }

    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
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