#include<bits/stdc++.h>
using namespace std;

int print_all_letters(){
    char arr[100] = "Anubhav anand";
    cin >> arr;
    for(int i=0; arr[i] != '\0'; i++){
        cout << arr[i] << "\n";
    }
}

int max_word(){
    char a[100];
    cin.getline(a,100);
    cin.ignore();
    
    int max = 0, current =0, previousSpace=0;
    int i=1;
    while(a[i]!='\0'){
        if(a[i]==' '){
            current == i-previousSpace;
            if(max<current)max = current;
            else previousSpace = i;
        }
        i++;
    }
    cout << max;
}

int solve(){
    //print_all_letters();
    max_word();
}



int input(){
    int test;
    cin >> test;
    for(int t=1;t<=test;t++){
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }
}

int main(){
    input();
}