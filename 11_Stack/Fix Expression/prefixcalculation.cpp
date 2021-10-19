#include<bits/stdc++.h>
using namespace std;

int prefix_calculation(string a){
    stack<int> st;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i] >= '0' && a[i] <= '9'){
            st.push(a[i] - '0');
        }
        else{
            char oper = a[i];
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();

            switch (oper)
            {
            case '+':
                st.push(operand1 + operand2);
                break;

            case '-':
                st.push(operand1 - operand2);
                break;  

            case '/':
                st.push(operand1 / operand2);
                break; 

            case '*':
                st.push(operand1 * operand2);
                break;
            
            default:
                break;
            }
        }

    }
    return st.top();
}

int solve(){
    string a = "/+459";
    cout << prefix_calculation(a);
}

int main(){
    solve();
}