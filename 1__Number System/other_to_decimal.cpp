#include<bits/stdc++.h>
using namespace std;

int binary(int n){
    int ans = 0;
    int i=0;
    while(n>0){
        int current_last_digit = n%10;
        ans += pow(2,i)*current_last_digit;
        n/=10; 
        i++;
    }
    return ans;
}

int octal(int n){
    int ans = 0;
    int i=0;
    while(n>0){
        int current_last_digit = n%10;
        ans += pow(8,i)*current_last_digit;
        n/=10; 
        i++;
    }
    return ans;
}

int hexa(string a){
    int n=0;
    while(a[n]!=0)n++;

    int ans=0;
    int j=0;
    for(int i=n-1;i>=0;i--){
        char current_last_digit = a[i];
        int int_for_digit;
        if(current_last_digit>='A' && current_last_digit<='F'){
            int_for_digit = current_last_digit + 10 - 'A';
        }   
        else int_for_digit = current_last_digit + 1 - '1';

        ans = ans + int_for_digit*pow(16,j);
        j++;

    }

    return ans;
    

}

int main(){
    int which_number_to_decimal = 0;

    //1 for binary
    //2 for octa
    //3 for hexa
    cin >> which_number_to_decimal;


    if(which_number_to_decimal==1){
        int n;
        cin >> n;
        cout << binary(n);
    }
    else if(which_number_to_decimal==2){
        int n;
        cin >>n;
        cout << octal(n);

    }
    else if(which_number_to_decimal==3){
        string a;
        cin >> a;
        cout << hexa(a);
    }

    
    return 0;
}