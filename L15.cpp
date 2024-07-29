//checking for balance binary tree
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int check(TreeNode* root){
    if(root==nullptr) return 0;
    int lh=check(root->left);
    if(lh==-1) return -1;
    int rh=check(root->right);
    if (rh==-1) return -1;
    if(abs(rh-lh)>1) return -1;
    return max(lh,rh)+1;
}
bool isBalance(TreeNode* root){
    return check(root)!=-1;
}

int main()
{

    // Creating a sample tree:
    //        3
    //       / \
    //      9  20
    //    /   /  \
    //  91  15    7
    //              \
    //               71
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(91);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(71);
    cout<<isBalance(root);
    
    return 0;
}