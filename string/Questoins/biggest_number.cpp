#include<bits/stdc++.h>
using namespace std;

string insertSort(string a){
    for(int i=0;i<(a.length()-1);i++){
        int j=i+1;
        while(a[j]>a[j-1] && j>0){
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1]= temp;
            j--;
        }
    }
    cout << a;
}

int biggest_number(){
    string a = "13412341234";
    insertSort(a);
    
}

int solve(){
    biggest_number();
}

int main(){
    solve();   
}