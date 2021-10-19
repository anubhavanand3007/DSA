#include<bits/stdc++.h>

using namespace std;

int binary(int n){
    int ans = 0, digit;
    for(int i =1; n>0; i*=10) {
        digit = n%2;
        n = n/2;
        ans =ans + digit*i;
    }
    return ans;
}

int octal(int n){
    int ans=0;
    int i=1;
    while(n>0){
        int lastDigit=n%8;
        n/=8;
        ans = ans +lastDigit*i;
        i*=10;
    }
    return ans;
}

string hexa(int n){
    char a[10] , last_char;
    for(int i=0;n>0;i++){
        int last_digit = n%16;
        if(last_digit>9 && last_digit<16){
            last_char = 'A'+last_digit-10;
        }
        else last_char = '1' + last_digit-1;

        a[i] = last_char;
        n=n/16;
    }

    int count=0;
    while(a[count]!=0)count++;

    for(int i=0;i<count/2;i++){
        char temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }

    return a;
}


int main(){
    //cout << "Anubhav";
    int n;
    cin >> n;
    cout << binary(n) <<"\n" << octal(n) << "\n" << hexa(n);

    return 0;
}