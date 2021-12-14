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

bool search(tree* root, int key){
    if(root == NULL)return false;
    if(root->data == key)return true;

    if(key<root->data)return search(root->left,key);
    else return search(root->right,key);
}

void inorder(tree* root){
    if(root == NULL )return ;
    inorder(root->left);       
    cout << root->data << ' ';
    inorder(root->right);
}

tree* rightmin(tree* root){
    tree* curr = root;
    while(curr->left !=NULL){
        curr = curr->left;
    }
    return curr;
}

tree* deleteinBST(tree* root, int val){
    if(val < root->data){
        root->left = deleteinBST(root->left,val);
    }
    else if(val > root->data){
        root->right = deleteinBST(root->right,val);
    }
    else{
        if(root->right == NULL){
            tree* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL){
            tree* temp = root->right;
            delete root;
            return temp;
        }
        else{
            tree* n = rightmin(root->right);
            n->left = root->left;
            delete root;
            return n;
        }
    }
    return root;
}

tree* constructBSTpreorder (int preorder[], int *idx, int min, int max, int n){
    if(*idx >= n){
        return NULL;
    }
    tree* node = NULL;
    if(preorder[*idx] > min && preorder[*idx] < max){
        node = new tree(preorder[*idx]);
        *idx = *idx + 1;
        if(*idx<n){
            node->left=constructBSTpreorder(preorder,idx,min,preorder[*idx-1],n);
        }
        if(*idx<n){
            node->right = constructBSTpreorder(preorder,idx,preorder[*idx-1],max,n);
        }
    }
    return node;
}

bool isBST(tree* root, int min, int max){
    if(root == NULL){
        return true;
    }

    if(root->data >= max or root->data <= min){
        return false;
    }

    bool lisBST = isBST(root->left,min,root->data);
    bool risBST = isBST(root->right,root->data,max);

    return lisBST && risBST;
}

int main(){
    tree* root = NULL;
    root = insertBST(root,12);
    insertBST(root, 5);
    insertBST(root, 15);
    insertBST(root, 3);
    insertBST(root, 7);
    insertBST(root, 13);
    insertBST(root, 17);
    insertBST(root, 1);
    insertBST(root, 9);
    insertBST(root, 18);

    inorder(root);
    cout << "\n";
    root = deleteinBST(root,15);
    inorder(root);
    cout << '\n';
    int n =0;
    int arr[] = {10,2,1,13,12};
    root = constructBSTpreorder(arr, &n,0,100,5);
    inorder(root);

    cout << '\n' << isBST(root,INT_MIN,INT_MAX);

}