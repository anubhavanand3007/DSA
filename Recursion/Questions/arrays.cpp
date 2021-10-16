#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n){
    if(n==0)return true;
    return (arr[n]>arr[n-1]) && isSorted(arr,n-1);
}

int decreasing(int n){
    if(n==0)return 0;
    decreasing(n-1);
    cout << n;
}


int increasing(int n){
    if(n==0)return 0;
    cout << n;
    increasing(n-1);
}

int firstocc(int arr[],int n, int i, int key){
    if(i == n)return -1;
    if(arr[i] == key)return i;
    return firstocc(arr,n,++i,key);
}

int lastocc(int arr[], int n,int i,int key){
    int restarr = lastocc(arr,n,++i,key);
    if(restarr == -1)return restarr;    
    if(arr[i] == key) return i;
    return -1;
}

int solve(){
    int arr[] = {1,2,3,4,5,6,7};
    int n=7;
    cout << isSorted(arr,n);
    cout << firstocc(arr,n,0,2) << " ";
    cout << lastocc(arr,n,0,2);
}

int main(){
    solve();   
}