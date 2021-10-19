#include<iostream>
using namespace std;

#define n 5
#define vi vector<int>

class queue{

    public:
    int data[n];
    int front = -1;
    int back = -1;

    void enquque(int val){
        if(front == -1){
            front++;
        }
        if(back == n-1){
            cout <<  "queue overflow";
            return;
        }
        back++;
        data[back] = val;
    }

    void dequeue(){
        if(front == -1 || front>back){
            cout << "queue empty";
            return;
        }
        front++;
    }

    int peek(){
        if(front == -1 || front>back){
            return -1;
        }
        return data[front];
    }

    bool empty(){
        if(front == -1){
            return true;
        }
        return false;
    }
};

int solve(){
    queue a;
    a.enquque(12);
    a.enquque(13);
    a.enquque(14);
    a.enquque(15);
    cout << a.peek();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();



    cout << a.peek();
}

int main(){
    solve();
}