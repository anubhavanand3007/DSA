#include<iostream>
#include<vector>
using namespace std;

class stack{
    private:
        vector<int> data;
        int top;

    public:
        stack(){
            top = -1;
        }
        string push(int val){
            top++;
            data.assign(top , val);
        }

        int pop(){
            if( top == -1)return -1;
            int val = data[top];
            --top;
            return val;
        }

        int Top(){
            if(top == -1)return -1;
            return data[top];
        }
};


int main(){
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);

    cout << s1.pop();
    cout << s1.pop();
    cout << s1.pop();
    cout << s1.Top();
}