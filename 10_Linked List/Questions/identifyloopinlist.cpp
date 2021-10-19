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



bool isloop(node* head){
    node *slow = head, *fast = head;
    do{
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }while(fast->next != NULL || fast!=NULL);
    return false;

}

void removeloop(node* &head){
    bool isloop = false;
    node *slow = head, *fast = head;
    do{
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
                isloop = true;
                break;
            }
    }while(fast->next != NULL || fast!=NULL);
    
    if(isloop){
        fast = head;
        while(fast->next != slow->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = NULL;
    }
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

    node* curr = head;
    int count = 1;
    node *betwn;
    while(curr!=NULL && count<5){
        curr = curr->next;
        count++;
    }
    betwn = curr;
    while(curr!=NULL && count<9){
        curr = curr->next;
        count++;
    }
    curr->next = betwn;



    cout << isloop(head) << endl;
    removeloop(head);
    display(head);
}