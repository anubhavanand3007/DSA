#include<bits/stdc++.h>
using namespace std;

int selection_sort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min = a[i];
        for(int j=i+1;j<n;j++){
            if(min>a[j]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }        
        }
    }


    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}



int bubble_sort(int a[], int n){
    
    int counter = 1;
    while(counter>n){
        for(int i=0; i<n-counter;i++){
            if(a[i]>a[i+1]){
                int temp=a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        counter++;
    }
}

int insert_sorting(int a[], int n){
    for(int i =1; i<n ; i++){
        int j =i;
        while(a[j]<a[j-1] && j>0){
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
    }
    for(int i = 0 ; i<n ; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int n;
    cin >>n;
    int a[n];
    for(int i = 0; i<n ;i++){
        cin >> a[i];
    }

    //bubble_sort(a,n);
    insert_sorting(a,n);
    //selection_sort(a,n);




    return 0;

}