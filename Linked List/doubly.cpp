#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* prev;
    int data;
    node* next;

    node(int val){
        next = NULL;
        prev = NULL;
        data = val;
    }
};

void push_back(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
    }
    else{
        node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = n;
        n->prev = curr;
    }
}

void push_front(node* &head, int val){
    node *n = new node(val);
    n->next = head;
    head->prev = n;
    head = n;
}


void display(node* &head){
    node* curr = head;
    while(curr != NULL){
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL";
}

void insert(node* &head, int val, int index){
    node *n = new node(val);
    if(index == 1){
        n->next = head;
        head->prev = n;
        head = n;
    }
    else{
        node *curr = head;
        for(int i=1;i<index-1;i++){
            curr = curr->next;
        }
        if (curr->next != NULL){
            n->prev = curr;
            n->next = curr->next;
            n->next->prev = n;
            curr->next = n;
        }
        else{
            n->prev = curr;
            curr->next = n;
        }
    }
}

void deletenode(node* &head, int index){
    if(index == 1){
        head->next->prev = NULL;
        node* del = head;
        head= head->next;
        delete del;
    }
    else{
        node *curr = head;
        for(int i=1;i<index-1;i++){
            curr = curr->next;
        }
        if(curr->next->next == NULL){
            node *del = curr->next;
            curr->next = NULL;
            delete del;
        }
        else{
            curr->next->next->prev = curr;
            node *del = curr->next;
            curr->next = curr->next->next;
            delete (del);
        }
    }
}

void display_rev(node* &head){
    cout << "NULL";
    node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    while(curr != NULL){
        cout << "<-" << curr->data;
        curr = curr->prev;
    }
}

void reverse(node* &head){
    node *prevs = NULL, *curr = head, *nexts=head->next;
    while(nexts != NULL){
        curr->next = prevs;
        curr->prev = nexts;
        prevs = curr;
        curr = nexts;
        nexts = nexts->next;
    }
    head = curr;
    curr->next = prevs;
    curr->prev = nexts;
}

int solve(){
    node*head = NULL;
    push_back(head, 1);
    push_back(head, 2);
    push_back(head, 3);
    push_back(head, 5);
    push_front(head, 0);
    insert(head, 4, 5);
    insert(head, 6, 7);
    deletenode(head, 7);

    reverse(head);
    display(head);
    cout << endl;
    display_rev(head);
}

int main(){
    solve();   
}