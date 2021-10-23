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

tree* insertBST(tree* root, int val){
    if(root == NULL){
        return new tree(val);
    }

    if(val < root->data){
        root->left = insertBST(root->left,val);
    }
    else{
        root->right = insertBST(root->right,val);
    }
}

void preorder(tree* root){
    if(root == NULL )return ;
    cout << root->data;
    preorder(root->left);       
    preorder(root->right);
}

int main(){
    tree* root = NULL;
    root = insertBST(root,6);
    insertBST(root, 4);
    insertBST(root, 3);
    insertBST(root, 2);
    insertBST(root, 1);
    insertBST(root, 5);
    insertBST(root, 7);
    insertBST(root, 8);
    insertBST(root, 9);

    preorder(root);

}