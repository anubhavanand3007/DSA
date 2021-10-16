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

void right_view(tree* &root){
    queue<tree*> q;
    q.push(NULL);
    q.push(root);

    while(!q.empty()){
        tree* front = q.front();
        q.pop();
        if(!q.empty()){
            int n = q.size();
            q.push(NULL);
            for(int i=0;i<n;i++){
                tree* fnode = q.front();
                if(i==n-1){
                    cout << fnode->data << " ";
                }

                if(fnode->left)q.push(fnode->left);
                if(fnode->right)q.push(fnode->right);
                q.pop();
            }
        }
        
    }
}

void left_view(tree* root){
    queue<tree*> q;
    q.push(NULL);
    q.push(root);

    while(q.back() != NULL){
        q.pop();
        int n = q.size();
        q.push(NULL);
        for(int i=0;i<n;i++){
            tree* node = q.front();
            if(i == 0)cout << node->data << ' ';

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);

            q.pop();
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

    right_view(root);
    cout << '\n';
    left_view(root);
}