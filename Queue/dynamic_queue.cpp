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

class queue{
    public:

    node* back;
    node* front;

    queue(){
        back = NULL;
        front = NULL;
    }

    void enqueue(int val){
        node* n = new node(val);
        if(front == NULL){
            front = n;
        }
        cout << "";
        if(back == NULL){
            back = n;
        }
        else{
            back->next = n;
            back = n;
        }
    }

    void dequeue(){
        if(front == NULL){
            cout << "queue empty";
            return;
        }
        node *del = front;
        front = front->next;
        if(front == NULL)back = NULL;
        delete del;
    }

    int peek(){
        if(front!=NULL ) return front->data;
        return -1;
    }

    bool empty(){
        if(front == NULL)return true;
        else return false;
    }

    int size(){
        int count = 0;
        node* n = front;
        while(n != back){
            count++;
            n=n->next;
        }
        return(++count);
    }

    int backp(){
        if(back!=NULL)return back->data;
        return -1;
    }

};

int solve(){
    queue a;
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);

    cout << a.peek();
    a.dequeue();
    cout << a.peek();
    a.dequeue();
    a.dequeue();

    a.dequeue();
    a.dequeue();

    cout << a.peek();
    cout << a.empty();
    cout << a.backp();
}

int main(){
    solve();
}

