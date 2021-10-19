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



node* mergesort(node* &head1, node*&head2){
    node* dummyhead = new node(0);
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* ptr3 = dummyhead;

    while(ptr1 !=NULL && ptr2 !=NULL){
        if(ptr1->data >= ptr2->data){
            ptr3->next = ptr2;
            ptr3 = ptr3->next;
            ptr2 = ptr2->next;
        }
        else{
            ptr3->next = ptr1;
            ptr3 = ptr3->next;
            ptr1 = ptr1->next;
        }
    }
    if(ptr1 == NULL){
        ptr3->next = ptr2;
    }
    else{
        ptr3->next = ptr1;
    }

    return dummyhead;
}


int main(){
	node *head1 = NULL;
	node *head2 = NULL;


    push_back(head1,1);
    push_back(head1,2);
    push_back(head1,3);
    push_back(head1,4);
    push_back(head1,5);
    push_back(head1,6);
    push_back(head1,7);
    push_back(head1,8);
    push_back(head1,9);

    push_back(head2,1);
    push_back(head2,3);
    push_back(head2,3);
    push_back(head2,4);
    push_back(head2,5);

    display(head1);
    cout << "\n";
    display(head2);
    cout << "\n";

    node* mergedlisthead = mergesort(head2,head1);
    display(mergedlisthead);
}