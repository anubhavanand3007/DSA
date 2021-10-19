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


node* evenafterodd(node* &head){
    node *oddhead=head, *evenhead = head->next;
    node *oddcurr = oddhead, *evencurr = evenhead;
    while(oddcurr->next!=NULL && evencurr->next !=NULL){
        oddcurr->next = oddcurr->next->next;
        oddcurr = oddcurr->next;
        evencurr->next = evencurr->next->next;
        evencurr = evencurr->next;
    }
    oddcurr->next=evenhead;

    return oddhead;
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
    head = evenafterodd(head);

    display(head);
}