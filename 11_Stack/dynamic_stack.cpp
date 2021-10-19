#include<iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class stack{
    public:
    node *top;

    stack(){
        top = NULL;
    }

    void push(int val){
        node* n = new node(val);
        if(top == NULL){
            top = n;
        }
        else{
            n->next = top;
            top = n;
        }
    }

    void pop(){
        if(top == NULL){
            cout << "Stack Empty";
            return;
        }
        else{
            node* del = top;
            top = top->next;
            delete del;
        }
    }

    int Top(){
        if(top != NULL)
        return top->data;
    }

    bool empty(){
        if(top == NULL)return true;
        return false;

    }
};

int solve(){
    stack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);

    cout << a.Top();
    a.pop();

    cout << a.Top();
    a.pop();
    
    cout << a.Top();
    a.pop();

    cout << a.Top();
    a.pop();

    cout << a.Top();
    a.pop();

}

int main(){
    solve();
}