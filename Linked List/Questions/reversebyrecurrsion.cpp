#include<bits/stdc++.h>
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

void push_back(node* &head, int val){
    node *n = new node(val);
    if(head == NULL){
        head = n;
    }
    else{
        node *curr = head;
        while(curr->next !=NULL){
            curr = curr->next;
        }
        curr->next = n;
    }
}


void display(node* &head){
    node *curr = head;
    while(curr != NULL){
        cout << curr->data <<"->";
        curr = curr->next;
    }
	cout << "NULL";
}


node* reverse(node* &head){
    node* curr = head;
    if(curr->next == NULL){
        return curr;
    }
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    node* store = curr->next;
    curr->next = NULL;
    node* rest = reverse(head);
    store->next = rest;
    return store;
}

node* reverse2(node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* newhead = reverse2(head->next);
    node* curr = newhead;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next=head;
    head->next = NULL;
    return newhead;
}

node* reversetillk(node* &head, int k){
    node *prevptr = NULL, *curr = head, *nextptr;
    int count =0;
    while(curr!=NULL && count <k){
        nextptr = curr->next;
        curr->next = prevptr;
        prevptr = curr;
        curr = nextptr;
        count++;
    }

    if(curr!=NULL){
        node *resthead = reversetillk(curr,k);
        head->next = resthead;
    }

    return prevptr;
}

int main(){
	node *head = NULL;

    push_back(head,1);
    push_back(head,2);
    push_back(head,3);
    push_back(head,4);
    push_back(head,5);
    push_back(head,6);
    push_back(head,7);
    push_back(head,8);
    push_back(head,9);

    // head = reverse2(head);
    head= reversetillk(head,2);

    display(head);
}