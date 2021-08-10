#include<bits/stdc++.h>
using namespace std;

int pointer_increment(){
    int *p;
    int a = 10;

    p = &a;
    cout << "a: " <<  a << " adress of a:" << &a << " value in p: " << p << " value pointer pointing: "<< *p ;

    p++;
    cout << p; //4 bytes increased
}

int array_pointer(){
    int *p;
    int a[] = {1,2,3,10,5};             //this a behaves like a pointer
    p = a;


    for(int i=0;i<5;i++){
        cin >> *(a+i);
        //a++ is illeagal because you cant change a's value as a is indexing pointer, hence +1 will make the pointer to the next index

    }

    for(int i=0;i<5;i++){
        cout <<"\n" << *p;
        p++;
    }
}


int pointer_to_pointer(){
    int a=10;
    int* p = &a;
    int** q = &p;

    cout << "value of a: " << a << "value of p: " << &a << "value of q: "<< &p;
    cout << "\nadress of a: " << &a << "Adress of p: "<< &p << " Adress of q: " << &q;
    cout << "\nPointing to --> *p: " << *p << " *q: " << *q << "**q: " << **q ;

}

void increment(int *p){
    (*p)++;                 //breacket is important
}


int solve(){
    pointer_increment();
    array_pointer();
    pointer_to_pointer();

    int a=10;
    cout << "\n" << a;
    increment(&a);
    cout <<"\n" << a;

}

int input(){
    int test;
    cin >> test;
    for(int t=1;t<=test;t++){
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;


    }
}
int main(){
    input();
}