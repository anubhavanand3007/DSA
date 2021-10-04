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

void push_front(node* &head, int val){
	node* n = new node(val);
	n->next = head;
	head = n;
}

void display(node* &head){
    node *curr = head;
    while(curr != NULL){
        cout << curr->data <<"->";
        curr = curr->next;
    }
	cout << "NULL";
}

void deletenode(node* &head, int index){
	node* forwardpointer = head;

	if (index == 1){
		head = forwardpointer->next;
		delete (forwardpointer);
	}
	else{
		node *curr = head;
		for (int i=2;i<index;i++){
			curr = curr->next;
		}
		node *n = curr->next;
		curr->next = n->next;

		delete (n);

	}
}

void insert(node* &head, int val, int index){
    node *n = new node(val);
    if (index == 1){
        n->next = head;
        head = n;
    }
    else{
        node* curr = head;
        for (int i=1;i<index-1;i++){
            curr = curr->next;
        }
        node *temp = curr->next;
        curr->next = n;
        n->next = temp;
    }
}

void clear(node* &head){
    node* curr = head;
    while(curr != NULL){
        node*temp = curr->next;
        delete (curr);
        curr = temp;
    }
    head = NULL;
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

    push_back(head,3);
    push_back(head,3);
	push_front(head,1);
	deletenode(head, 2);
    insert(head,2,2);
    insert(head,0,1);
    // clear(head);
    push_back(head,4);
    push_back(head,5);
    // push_back(head,6);

    // head = reverse2(head);
    head= reversetillk(head,2);

    display(head);
}