#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int val){
        data = val;
    }
};

void push_back(node *&head, int val){
    node *n = new node(val);
    n->next = n;
    if(head == NULL){
        head = n;
    }
    else{
        node *curr = head;
        do{
            curr = curr->next;
        }while(curr->next != head);
        n->next = head;
        curr->next = n;
    }
}

void insert(node *&head, int val, int index){
    node *n = new node(val);
    if(index == 1){
        n->next = head;

        node* curr = head;
        do{
            curr = curr->next;
        }while(curr->next != head);
        curr->next = n;
        head = n;
    }
    else{
        node* curr = head;
        for(int i=1;i<index-1;i++){
            curr = curr->next;
        }
        if(curr->next == head){
            n->next = head;
            curr->next = n;
        }
        else{
            node* curr = head;
            for(int i=1;i<index-1;i++){
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
    }
}

void display(node* &head){
    node *curr = head;
    do{
        cout<< curr->data<< "->";
        curr = curr->next;
    }while(curr != head);
    cout << "end" << "->";
    cout << curr->data << "->";
    cout << curr->next->data;
}

void deletenode(node* &head, int index){
    node* curr = head;
    if(index == 1){
        node *del = head;
        do{
            curr = curr->next;
        }while(curr->next != head);
        curr->next = head->next;
        head = head->next;
        delete del;
    }
    else{
        for(int i=1;i<index-1;i++){
            curr = curr->next;
        }
        if(curr->next->next != head){
            node *del = curr->next;
            curr->next = del->next;
            delete del;
        }
        else{
            node *del = curr->next;
            curr->next = head;
            delete del;
        }

    }
}

void reverse(node *&head){
    node* prev = NULL;
    node* curr = head;
    node* nexts = head->next;
    while(nexts != head){
        curr->next = prev;
        prev = curr;
        curr = nexts;
        nexts = nexts->next;
    }
    head->next=curr;
    curr->next = prev;
    head = curr;
    
}



int solve(){
    node* head = NULL;
    push_back(head, 123);
    push_back(head, 2);
    push_back(head, 3);
    insert(head,0,4);
    deletenode(head, 2);

    reverse(head);
    display(head);
    return 0;
}

int main(){
    solve();
    return 0;
}