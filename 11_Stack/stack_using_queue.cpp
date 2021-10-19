#include<iostream>
#include<queue>
using namespace std;

class stack{
    public:
    queue<int> que;
    queue<int> backup;

    void push(int val){
        while(!que.empty()){
            backup.push(que.front());
            que.pop();
        }
        que.push(val);
        while(!backup.empty()){
            que.push(backup.front());
            backup.pop();
        }
    }

    void pop(){
        que.pop();
    }

    int top(){
        return que.front();
    }
};

int solve(){
    stack a;

    a.push(1);
    a.push(2);
    a.push(3);

    cout << a.top();

    a.pop();

    cout << a.top();

}

int main(){
    solve();
}