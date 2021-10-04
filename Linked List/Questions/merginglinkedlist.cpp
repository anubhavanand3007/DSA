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