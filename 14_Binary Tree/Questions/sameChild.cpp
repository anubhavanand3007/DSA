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

int sameChild(tree* root){
    if(root->left == NULL || root->right == NULL){
        return 1;
    }
    int lcount = sameChild(root->left);
    int rcount = sameChild(root->right);
    int i=0;
    if(root->data == root->left->data && root->data == root->right->data)i=1;

    return i+lcount+rcount;
}


int main(){
    tree* root = new tree(1);
    root->left = new tree(1);
    root->right = new tree(1);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    cout << sameChild(root);
}