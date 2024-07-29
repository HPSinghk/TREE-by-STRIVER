// MAXIMUM PATH SUM OF A TREE

#include<bits/stdc++.h>
#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxPathSum(TreeNode* root,int *ans){
    if(root==nullptr) return 0;
    int lsum = maxPathSum(root->left,ans);
    int rsum = maxPathSum(root->right,ans);
    *ans = max(*ans,root->val+lsum+rsum);
    return root->val+max(lsum,rsum);


}
int main()
{
   /*  TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(91);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->left->right = new TreeNode(25);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(71); */

    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int ans=0;
    maxPathSum(root,&ans);
    cout<<ans;
    return 0;
}