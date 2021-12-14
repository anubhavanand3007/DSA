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

tree* sorted_array_to_BST(int arr[] ,int min, int max){
    if(min>max){
        return NULL;
    }
    int mid = (max+min)/2;
    tree* root = new tree(arr[mid]);

    root->left = sorted_array_to_BST(arr,min,mid-1);
    root->right = sorted_array_to_BST(arr,mid+1,max);

    return root;
}

void inorder(tree* root){
    if(root == NULL){
        return;
    }
        cout << root->data << ' ';
    inorder(root->left);

    inorder(root->right);
}

int main(){
    int arr[] = {1,2,3,4,5};
    tree* root = sorted_array_to_BST(arr,0,4);
    inorder(root);
}