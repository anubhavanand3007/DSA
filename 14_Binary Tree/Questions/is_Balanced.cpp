#include<iostream>
#include<queue>
using namespace std;

class treeNode{
    public:
    int data;
    treeNode* left;
    treeNode* right;

    treeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool is_Balanced(treeNode* root, int *height){
    if(root == NULL){
        return true;
    }
    int lh=0, rh=0;
    
    if(!is_Balanced(root->left, &lh)){
        return false;
    }
    if(!is_Balanced(root->right, &rh)){
        return false;
    }

    *height = max(lh,rh)+1;

    if(abs(rh - lh) > 1){
        return false;
    } else{
        return true;
    }
}

int solve(){
    treeNode* root = NULL;
    root = new treeNode(1);
    root->left = new treeNode(2);
    root->right = new treeNode(3);
    root->right->left = new treeNode(4);

    int height = 0;

    cout << is_Balanced(root, &height);

}

int main(){
    solve();
}