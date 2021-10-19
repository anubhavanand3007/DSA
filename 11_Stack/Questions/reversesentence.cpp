#include<bits/stdc++.h>
using namespace std;


string reversesentence(string prev){
    stack<string> st;

    string final = "", word = "";
    for(int i=0;i<prev.size();i++){
        if(prev[i] != ' '){
            word.push_back(prev[i]);
        }
        else{
            st.push(word);
            word = "";
        }
    }
    st.push(word);
    word = "";

    while(st.size()){
        cout << st.top() << " ";
        st.pop();
    }
}

int solve(){
    string a = "my name is anubhav anand";
    reversesentence(a);
}

int main(){
    solve();   
}