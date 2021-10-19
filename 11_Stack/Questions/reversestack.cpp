#include<bits/stdc++.h>
using namespace std;

void puttobottomoflist(stack<int> &st, int elem){
    if(st.empty()){
        st.push(elem);
        return;
    }

    int topelem = st.top();
    st.pop();
    puttobottomoflist(st, elem);

    st.push(topelem);
}

void reversestack(stack<int> &st){

    if(st.empty()){
        return;
    }

    int elem = st.top();
    st.pop();
    reversestack(st);
    puttobottomoflist(st,elem);
}

int solve(){
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    for(int i=0;i<5;i++){
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reversestack(st);

    for(int i=0;i<5;i++){
        cout << st.top() << " ";
        st.pop();
    }

}


int main(){
    solve();   
}