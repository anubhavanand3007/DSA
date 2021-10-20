

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};
 
TreeNode* newTreeNode(int data)
{
    TreeNode* temp = new TreeNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 

void productOfLevelSumUtil(TreeNode* root,
       unordered_map<int, int>& level_sum,
                                int level)
{
 
    if (!root)
        return;
 

    if (!root->left && !root->right)
        level_sum[level] += root->data;
 

    productOfLevelSumUtil(root->left, level_sum,
                          level + 1);
 

    productOfLevelSumUtil(root->right, level_sum,
                          level + 1);
}
 

int productOfLevelSum(TreeNode* root)
{

    unordered_map<int, int> level_sum;

    productOfLevelSumUtil(root, level_sum, 0);
 

    int prod = 1;
 

    for (auto it = level_sum.begin();
                it != level_sum.end(); it++)
        prod *= it->second;
 

    return prod;
}
 
// Driver Code
int main()
{
    // Creating Binary Tree
    TreeNode* root = newTreeNode(2);
    root->left = newTreeNode(7);
    root->right = newTreeNode(5);
    root->left->right = newTreeNode(6);
    root->left->left = newTreeNode(8);
    root->left->right->left = newTreeNode(1);
    root->left->right->right = newTreeNode(11);
    root->right->right = newTreeNode(9);
    root->right->right->left = newTreeNode(4);
    root->right->right->right = newTreeNode(10);
 
    cout << "Final product is = "
         << productOfLevelSum(root) << endl;
 
    return 0;
}