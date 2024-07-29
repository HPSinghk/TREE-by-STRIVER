// DIAMETER OF TREE
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int maxi=0;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int diameter(TreeNode* root){
    if(root == nullptr) return 0;
    int lh = diameter(root->left);
    int rh = diameter(root->right);
    maxi = max(maxi,lh+rh);
    return 1+max(lh,rh);

}

int main()
{

    // Creating a sample tree:
    //        3
    //       / \
    //      9  20
    //    /   /  \
    //  91  15    7
    //        \     \
    //         25    71
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(91);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->left->right = new TreeNode(25);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(71);
    diameter(root);
    cout<<maxi;
    
    return 0;
}