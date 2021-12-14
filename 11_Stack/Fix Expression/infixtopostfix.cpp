#include<bits/stdc++.h>
using namespace std;

int precedence(char a){
    if (a == '^')return 3;
    else if(a== '*' || a == '/')return 2;
    else if(a == '+' || a == '-') return 1;
    else return -1;
}

string infix_to_postfix(string s){
    stack<char> st;
    string postfix = "";
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            postfix+=s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            do{
                postfix+=st.top();
                st.pop();
            }while(!st.empty() && s[i] !='(');
        }
        else{
            while(!st.empty() && precedence(s[i]) < precedence(st.top())){
                postfix+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int solve(){
    string infix = "0+0/0";

    string postfix = infix_to_postfix(infix);
    cout << postfix;
}

int main(){
    solve();
}