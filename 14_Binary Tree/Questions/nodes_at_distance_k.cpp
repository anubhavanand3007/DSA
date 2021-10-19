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

void node_at_distance_k(tree* root, tree* target, int k){
    //case 1 - subtree
    if(k>=0)node_at_distance_k_subtree_utils(target,k);
    else return;

    //case 2 - ancestor
    pair<tree*,char> ancestor = node_at_distance_k_ancestor_utils(root,target);
    if(ancestor.second == 'l') node_at_distance_k(root, ancestor.first->left, k-2);
    if(ancestor.second == 'r') node_at_distance_k(root, ancestor.first->right, k-2);
}


bool getPath(tree* root, tree*target, string &path){
    if(root == NULL){
        return false;
    }


    if(root == target){
        return true;
    }
    if(getPath(root->left,target,path)){
        path = 'l' + path;
        return true;
    }
    if(getPath(root->right,target,path)){
        path = 'r' + path;
        return true;
    }

    
    return false;
}

void node_at_distance_k_optimized(tree* root, tree* target, int k){
    string a;
    getPath(root,target,a);

    int n =a.size();

    if(n>=k){
        int d =0;
        tree* node = root;
        for(int i=0;i<n-k;i++){
            if(a[i] == 'l')node = node->left;
            else node = node->right;
        }
        node_at_distance_k_subtree_utils(node, d++);
        for(int i=n-k;i<n;i++){
            if(a[i] == 'l'){
                node = node->left;
                node_at_distance_k_subtree_utils(node,d++);
            }
            else{
                node = node->right;
                node_at_distance_k_subtree_utils(node,d++);
            }
        }
    }
    else{
        node_at_distance_k_subtree_utils(target,k);
        if(a[0] == 'l'){
            node_at_distance_k_subtree_utils(root->right,k-n-1);
        }
        else{
            node_at_distance_k_subtree_utils(root->left,k-n-1);
        }
    }

}

int main(){
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    vector<int> a;
    node_at_distance_k_optimized(root,root->left->right,2);
    for(int i:a){
        cout << i << " ";
    }
}