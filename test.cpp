#include<bits/stdc++.h>
using namespace std;

void removerepreate(string s){
    if(s.size() == 1){
        cout << s[0];
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    if(ch == ros[0]){
        removerepreate(ros);
    } else{
        cout << ch;
        removerepreate(ros);
    }
}


int main(){
    string s = "12312333";
    removerepreate(s);
}