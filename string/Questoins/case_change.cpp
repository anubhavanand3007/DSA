#include<bits/stdc++.h>
using namespace std;

int toUppercase(){
    string s1 = "qwerQWETQYy";
    cout << s1 << endl;
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='A' && s1[i]<='Z') s1[i] = s1[i] - 'A' + 'a';
    }
    cout <<s1<<endl;
}

int toLowercase(){
    string s1 = "qwerQWETQYy";
    cout << s1 << endl;
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='a' && s1[i]<='z') s1[i] = s1[i] - 'a' + 'A';
    }
    cout <<s1;
}

int solve(){
    toUppercase();
    toLowercase();
}

int main(){
    solve();
}