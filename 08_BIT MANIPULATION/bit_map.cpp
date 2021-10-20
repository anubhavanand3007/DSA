#include<bits/stdc++.h>
using namespace std;

int getbit(int n, int pos){
    int finder = 1<<(pos-1);
    int answer = n & finder;
    if(answer == 0) return 0;
    else return 1;
}

int setbit(int n,int pos){
    int setter = 1<<(pos-1);
    int answer = n | setter;
    return answer;
}

int clearbit(int n,int pos){
    int setter = ~(1<<(pos-1));
    int answer = n & setter;
    return answer;
}

int updatebit(int n,int pos, int value){
    if(value == 1)return setbit(n,pos);
    else return clearbit(n,pos);
}


int solve(){
    int n=5, pos=3, value 1;
    cout << getbit(n,pos) << endl;
    cout << setbit(n,pos) << endl;
    cout << clearbit(n,pos) << endl;
    cout << updatebit(n,pos, value) << endl;

}

int main(){
    solve();    
}