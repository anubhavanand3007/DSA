#include<bits/stdc++.h>
using namespace std;

int precedence(char a){
    if(a == '^')return 3;
    else if( a== '/' || a == '*')return 2;
    else if(a == '+' || a == '-')return 1;
    else return -1;
}

string infix_to_prefix(string s){
    for(int i=0;i<s.size()/2;i++){
        char temp = s[i];
        s[i] = s[s.size()-i-1];
        s[s.size()-i-1] = temp;
    }
    for(int i=0;i<s.size();i++){
        if(s[i] == '(')s[i] = ')';
        else if(s[i] == ')')s[i] = '(';
    }

    stack<char> st;
    string prefix = "";
    for(int i=0;i<s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            prefix += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                prefix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && precedence(st.top()) > precedence(s[i])){
                prefix+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        prefix+=st.top();
        st.pop();
    }

    s = prefix;

    for(int i=0;i<s.size()/2;i++){
        char temp = s[i];
        s[i] = s[s.size()-i-1];
        s[s.size()-i-1] = temp;
    }

    return s;
}

int solve(){
    string infix = "(5+3)-2/2";
    cout << infix_to_prefix(infix);
}

int main(){
    solve();
}