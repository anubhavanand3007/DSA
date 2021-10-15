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

int countNode(tree* root){
    if(root == NULL){
        return 0;
    }
    return countNode(root->left) + countNode(root->right) + 1;
}

int sum_of_all_nodes(tree* root){
    if(root == NULL){
        return 0;
    }
    int sum = sum_of_all_nodes(root->right)+sum_of_all_nodes(root->left)+root->data;
    return sum;
}

int calHeight(tree* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    return max(lHeight,rHeight) + 1;
}

int calDiameter(tree* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    int currDiameter = lHeight + rHeight +1;

    int lDiameter = calDiameter(root->left);
    int rDiameter = calDiameter(root->right);

    return max(lDiameter, max(rDiameter, currDiameter));
}

pair<int,int> calDiameter_optimized_utils(tree *root){
    if(root == NULL){
        return {0,0};
    }

    pair<int,int> lDiameter = calDiameter_optimized_utils(root->left);
    pair<int,int> rDiameter = calDiameter_optimized_utils(root->right);

    pair<int,int> currDiameter = {
        max(
            lDiameter.first,
            rDiameter.first
        )+1,
        max(
            lDiameter.first + rDiameter.first + 1,
            max(
                lDiameter.second,
                rDiameter.second
            )
        )
    };

    return currDiameter;
}

int calDiameter_optimized(tree* root){
    pair<int,int> a = calDiameter_optimized_utils(root);
    return max(a.first,a.second);
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

    cout << countNode(root) << '\n';
    cout << sum_of_all_nodes(root) << '\n';
    cout << calHeight(root) << '\n';
    cout << calDiameter(root) << '\n';
    cout << calDiameter_optimized(root) << '\n';
}