#include<bits/stdc++.h>
using namespace std;

bool bracket_odering(string s){
    stack<char> st;

    for(int i=0;i<s.size();i++){
        if(s[i] == '(' ||s[i] == '{' ||s[i] == '['){
            st.push(s[i]);
        }
        else{
            switch (s[i]){
                case '}':
                    if(st.top() == '{'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                    break;
                case ']':
                    if(st.top() == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                    break;
                case ')':
                    if(st.top() == '('){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                    break;
                
                default:
                    break;
            }
        }
    }
    return true;
}

int solve(){
    string exp = "[{[{()()}]}]";
    cout << bracket_odering(exp);
}

int main(){
    solve();
}