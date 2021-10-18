#include<bits/stdc++.h>
using namespace std;

class tree{
    public:
    int data;
    tree* left;
    tree* right;

    tree(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

tree* LCA(tree* root, tree* n1, tree*n2){
    if(root == NULL){
        return NULL;
    }

    if(root == n1 or root == n2){
        return root;
    }

    tree* lnode = LCA(root->left,n1,n2);
    tree* rnode = LCA(root->right,n1,n2);
    if(rnode && lnode)return root;
    if(lnode)return lnode;
    if(rnode)return rnode;

    return NULL;
}


int main(){
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    cout << LCA(root, root->left->left, root->left->right)->data;
}