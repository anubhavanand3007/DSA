#include<bits/stdc++.h>
using namespace std;

int PrimeSieve(int n){
    int a[100] = {0};
    for(int i=2;i<n;i++){
        if(a[i]==1)break;
        for(int j=i*i;j<n;j+=i){
            a[j]=1;
        }
    }
    for(int i=2;i<n;i++){
        if(a[i]==0)cout << i << " ";
    }
}

int PrimeFactors(int n){
    int spf[100] = {0};
    for(int i=0;i<n;i++) spf[i]=i;
    for(int i =2 ;i<n;i++){
        if(spf[i] == i)
            for(int j=i*i;j<n;j+=i) 
                if(spf[j] == j) spf[j] = i;
    }

    while(n!=1){
        cout << spf[n] << " ";
        n /= spf[n];
    }
}

int main(){
    int n=98;
    //PrimeSieve(n);
    PrimeFactors(n);
}