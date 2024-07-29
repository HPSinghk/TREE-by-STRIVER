//  VERTICAL ORDER TRAVERSAL OF TREE
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalOrder(TreeNode* root){
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<TreeNode*,pair<int,int>>> todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->val);
        if(node->left){
            todo.push({node->left,{x-1,y+1}});
        }
        if(node->right){
            todo.push({node->right,{x+1,y+1}});
        }
    }

       vector<vector<int>> ans;
       for(auto p : nodes){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
       }
       return ans;
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
    root->right->right->left = new TreeNode(60);
    root->right->right->right = new TreeNode(71);
    
   vector<vector<int>> x = verticalOrder(root);

   for(auto p:x){
    for(auto q:p)
       cout<<q<<" ";
   cout<<endl;   
   }

    
    
    return 0;
}