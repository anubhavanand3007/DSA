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

int sum_at_k_level(tree* &root, int k){
    queue<tree*> q;
    q.push(root);
    q.push(NULL);
    while(k and !q.empty()){
        tree* n = q.front();
        q.pop();
        if(n !=NULL){
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        else if(!q.empty()){
            q.push(n);
            k--;
        }
    }

    int sum=0;
    while(!q.empty()){
        if(q.front() != NULL) sum+= q.front()->data;
        q.pop();
    }
    return sum;
}

int solve(){
    ;
}

int main(){
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    cout << sum_at_k_level(root,2);
}