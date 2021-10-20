#include<bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0;i<n;i++)

pair<int,int> potimized(int arr[], int n, int k){
    int sum = arr[0];
    int pointer1 =0, pointer2 = 0;
    while(pointer1>0){
        if(sum<k){
            pointer2++;
            sum+=arr[pointer2];
        }
        else if(sum>k){
            pointer1++;
            sum -= arr[pointer1-1];
        }
        else{
            if(pointer1>pointer2) return {pointer1,pointer2};
            else return {pointer2, pointer1};
        }
    }
}

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
        for(int j=i+1;j<n;j++){
            if(k==curr){
                ansi =i+1;
                ansj =j;
                break;
            }
            curr+=a[j];
        }
        curr=0;
    }

    cout << ansi << " " << ansj <<endl;

    cout << potimized(a,n,k).first<< " " << potimized(a,n,k).second;
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