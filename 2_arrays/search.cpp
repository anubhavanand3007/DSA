#include<bits/stdc++.h>
using namespace std;

bool linear_search(int a[], int n, int key){
    for(int i =0; i<n; i++){
        if(a[i]==key){
            return true;
            break;
        }
    }
    return false;
}

int binary_search(int a[], int n, int key){
    int m , h=n-1 , l=0;
    while(l<h){
        m=(h+l)/2;
        if(a[m]==key){
            return true;
            break; 
        }
        else if(a[m]>key)h=m;
        else l=m;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int key;
    cin >>key;
    int linear = linear_search(a,n,key);
    int binary = binary_search(a,n,key);
    cout << linear << " " << binary;
    return 0;
}