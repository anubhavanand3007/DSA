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

void node_at_distance_k_subtree_utils(tree* node, int k){
    if(node == NULL)return;
    if(k == 0 and node != NULL){
        cout << node->data << " ";
        return;
    }
    node_at_distance_k_subtree_utils(node->left,k-1);
    node_at_distance_k_subtree_utils(node->right,k-1);
}

pair<tree*,char> node_at_distance_k_ancestor_utils(tree* root,tree* node){
    queue<tree*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            tree* a = q.front();
            if(a->left)q.push(a->left);
            if(a->left == node)return{a,'r'};

            if(a->right)q.push(a->right);
            if(a->right == node)return{a,'l'};

            q.pop();
        }
    }
}

bool getPath(tree* root, tree*target, string &path){
    if(root == NULL){
        return false;
    }


    if(root == target){
        return true;
    }
    if(getPath(root->left,target,path)){
        path += 'l';
        return true;
    }
    if(getPath(root->right,target,path)){
        path += 'r';
        return true;
    }

    
    return false;
}

int main(){
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    string a;
    getPath(root,root->left->right,a);
    cout << a;
}