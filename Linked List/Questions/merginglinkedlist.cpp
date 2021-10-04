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


node* ismerged(node *&head1, node *&head2){
    int count =1;
    node* curr = head1;
    while(curr->next !=NULL){
        curr = curr->next;
        count++;
    }
    int length1 = count;
    count = 1;
    curr = head2;
    while(curr->next !=NULL){
        curr = curr->next;
        count++;
    }
    int length2=count;
    int difflength;

    node* ptr1, *ptr2;
    if(length1>length2){
        difflength = length1-length2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        difflength = length2-length1;
        ptr1 = head2;
        ptr2 = head1;
    }

    count =0;
    while(count<difflength){
        ptr1 = ptr1->next;
        count ++;
    }

    while(ptr1 != ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return ptr1;
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
    push_back(head2,2);
    push_back(head2,3);
    push_back(head2,4);
    push_back(head2,5);

    node* mergepoint = new node(20);

    node* curr = head1;
    while(curr->next !=NULL)curr = curr->next;
    curr->next = mergepoint;

    curr = head2;
    while(curr->next !=NULL)curr = curr->next;
    curr->next = mergepoint;
    
    push_back(head1,21);
    push_back(head2,22);

    display(head1);
    cout << "\n";
    display(head2);

    cout << "\n";
    cout << ismerged(head1,head2)->data;
}