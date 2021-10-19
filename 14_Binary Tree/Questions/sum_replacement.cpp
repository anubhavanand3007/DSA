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

void sumReplace(tree* &root){
    if(root == NULL){
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left != NULL){
        root->data += root->left->data;
    }
    if(root->left != NULL){
        root->data += root->right->data;
    }
}

void preorder(tree* root){
    if(root == NULL){
        return;
    }
    cout << root->data << '-';
    preorder(root->left);
    preorder(root->right);
}

int main(){
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);
    preorder(root);
    cout << '\n';
    sumReplace(root);
    preorder(root);
}