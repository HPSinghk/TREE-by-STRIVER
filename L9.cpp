// iterative pre order traversal (ROOT LEFT RIGHT)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode* root){
    stack<TreeNode*> stk;
    if(root==nullptr) return;
    stk.push(root);
    while(!stk.empty()){
        TreeNode *node = stk.top();
        cout<<node->val<<" ";
        stk.pop();
        if(node->right!=nullptr) stk.push(node->right);
        if(node->left!=nullptr) stk.push(node->left);
    }
}

int main()
{
     // Creating a sample tree:
    //        3
    //       / \
    //      9  20
    //        /  \
    //       15   7
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    preOrder(root);
    
    return 0;
}