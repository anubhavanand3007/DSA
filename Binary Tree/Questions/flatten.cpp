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

tree* flatten (tree* root){
    if(root == NULL){
        return NULL;
    }
    tree* leftnode = flatten(root->left);
    tree* rightnode = flatten(root->right);

    root->left = NULL;
    root->right = leftnode;

    tree* n = leftnode;
    if(n!=NULL){
        while(n->right != NULL){
            n = n->right;
        }
        n->right = rightnode;
    }
    return root;
}

int main(){
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    root = flatten(root);
    tree* n = root;
    while(n != NULL){
        cout << n->data << " ";
        n = n->right;
    }

}