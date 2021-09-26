#include<bits/stdc++.h>
using namespace std;

int Sum(int n){
    if(n==0)return 0;
    else return n+Sum(n-1);
}

int power(int n,int p){
    if(p==0)return 1;
    return n * power(n,p-1);
}

int factorial(int n){
    if(n==1)return 1;
    return n*factorial(n-1);
}

int nthfibonachi(int n){
    if(n==0 || n==1) return n;
    return nthfibonachi(n-1)+nthfibonachi(n-2);
}

int solve(){
    int n, p;
    cin >> n >> p ;
    cout << Sum(n) << endl;
    cout << power(n,p) << endl;
    cout << factorial(n) << endl;
    cout << nthfibonachi(n);
}

int main(){
   solve(); 
}