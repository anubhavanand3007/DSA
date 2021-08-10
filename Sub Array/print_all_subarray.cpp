#include<bits/stdc++.h>
using namespace std;

int print_all_subarrays(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout << a[j] << " ";
                
            }
            cout << endl;
        }
        cout << endl;
    }
}

int sum_of_all_subarrays(int a[],int n){
    int sum =0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum += a[j];
            cout << sum << endl;
        }
        sum=0;
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    print_all_subarrays(a,n);
    sum_of_all_subarrays(a,n);

}