#include<iostream>
#include<stack>
using namespace std;

class queue{
    public:
    stack<int> st1;
    stack<int> st2;

    queue(){
        ;
    }

    void enqueue(int val){
        st1.push(val);
    }

    void dequeue(){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st2.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }

    int peek(){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int top = st2.top();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return top;
    }

    bool empty(){
        if(st1.empty())return true;
        else return false;
    }
};

int solve(){
    queue a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);

    cout << a.peek();

    a.dequeue();

    cout << a.peek();


}

int main(){
    solve();
}