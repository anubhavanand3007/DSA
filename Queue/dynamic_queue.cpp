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
        if(front == NULL || back->next == front){
            cout << "queue empty";
            return;
        }
        node *del = front;
        front = front->next;
        delete del;
    }

    int peek(){
        if(front!=NULL) return front->data;
    }

    bool empty(){
        if(back->next == front || front == NULL)return true;
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

    int back(){
        if(back->next != front && back!=NULL)return back->data;
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




}

int main(){
    solve();
}