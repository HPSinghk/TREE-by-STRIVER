// BOTTOM VIEW OF THE TREE
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> bottomView(TreeNode* root){
    vector<int> ans;
    map<int,TreeNode*> mp;
    queue<pair<TreeNode*,int>> que;
    que.push({root,0});
    while(!que.empty()){
        auto it = que.front();
        que.pop();
        TreeNode* node = it.first;
        int x = it.second;
        mp[x] = node;
        if(node->left){
            que.push({node->left,x-1});
            }
        if(node->right){
            que.push({node->right,x+1});
            }
    }
    for(auto x: mp){
        ans.push_back(x.second->val);
    }
    return ans;
}


int main()
{
 /*       3
         / \
        9   20
       /   /  \
      91  15   7
           \  / \
           25 60 71
 */

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(91);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->left->right = new TreeNode(25);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(60);
    root->right->right->right = new TreeNode(71);

    vector<int> x = bottomView(root);
    for(auto p:x){
        cout<<p<<" ";
    }
    
    
    return 0;
}