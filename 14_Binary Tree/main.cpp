#include<iostream>
#include<queue>
using namespace std;

class treeNode{
    public:
    int data;
    treeNode* left;
    treeNode* right;

    treeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int arr[], int st, int end, int curr){
    for(int i=st;i<end;i++){
        if(arr[i] == curr){
            return i;
        }
    }
}

treeNode* buildTree(int inorder[], int preorder[], int st, int end){

    if(st>end){
        return NULL;
    }

    static int idx = 0;
    int curr = preorder[idx];
    idx++;

    treeNode* root = new treeNode(curr);
    int pos = search(inorder,st,end,curr);

    root->left = buildTree(inorder,preorder,st,pos-1);
    root->right = buildTree(inorder,preorder,pos+1,end);

    return root;
}

void preorder_traversal(treeNode *root){
    if(root == NULL){
        return;
    }

    cout << root->data;
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(treeNode *root){
    if(root == NULL){
        return;
    }

    inorder_traversal(root->left);
    cout << root->data;
    inorder_traversal(root->right);
}

void postorder_traversal(treeNode *root){
    if(root == NULL){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data;
}

int levelorder(treeNode* root){
    if( root == NULL){
        return 0;
    }

    queue<treeNode*> que;
    que.push(root);
    que.push(NULL);

    while(!que.empty()){
        treeNode* n = que.front();
        que.pop();
        if(n != NULL){
            cout << n->data << " ";
            if(n->left) que.push(n->left);
            if(n->right) que.push(n->right);
        }
        else if(!que.empty()){
            que.push(n);
        }

    }

}

int solve(){
    treeNode* root = NULL;
    root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);

    preorder_traversal(root);
    cout << '\n';
    inorder_traversal(root);
    cout << '\n';
    postorder_traversal(root);
    cout << "\n\n";

    int inorder[] = {4,2,1,5,3};
    int preorder[] = {1,2,4,3,5};

    root = buildTree(inorder,preorder,0,4);
    preorder_traversal(root);
    levelorder(root);

}

int main(){
    solve();
}