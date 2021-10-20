#include<bits/stdc++.h>
using namespace std;

int maxfrequency(){
    string a= "aabbbcccc";
    int freq[26];

    for(int i=0;i<26;i++)freq[i]=0;

    for(int i=0;i<a.size();i++){
        ++freq[a[i]-'a'];
    }

    int max =0;
    char chr;
  
    for(int i=0;i<26;i++){
        if(freq[i]>max){
            max = freq[i];
            chr = i+'a';
        }
    }
    cout << chr;
}

int solve(){
    maxfrequency();
}

int main(){
    solve();  
}