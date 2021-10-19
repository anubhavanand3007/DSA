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

void reverse(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* nexts = head->next;
    while(nexts!=NULL){
        curr->next = prev;
        prev = curr;
        curr = nexts;
        nexts = nexts->next;
    }
    head = curr;
    curr->next = prev;

}

int main(){
	node *head = NULL;

    push_back(head,1);
    push_back(head,2);
	push_front(head,3);
	deletenode(head, 2);
    insert(head,34,2);
    insert(head,12,1);
    // clear(head);
    push_back(head,1);
    reverse(head);

    display(head);
}