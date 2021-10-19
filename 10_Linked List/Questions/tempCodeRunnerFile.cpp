
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
    int count =0;
    node* curr = head1;
    while(curr->next !=NULL){
        curr = curr->next;
        count++;
    }
    int length1 = count;
    count = 0;
    curr = head2;
    while(curr->next !=NULL){
        curr = curr->next;