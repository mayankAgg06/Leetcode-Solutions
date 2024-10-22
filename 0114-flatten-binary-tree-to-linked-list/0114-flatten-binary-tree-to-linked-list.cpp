/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*> &preorder)
    {
        if(!root)return;

        preorder.push_back(root);
        inorder(root->left,preorder);
        inorder(root->right,preorder);
    }
    void flatten(TreeNode* root) {

        if(!root)return;
        
        vector<TreeNode*> preorder;

        inorder(root,preorder);

        for(int i=1;i<preorder.size(); i++)
        {
            preorder[i-1]->right = preorder[i];
            preorder[i-1]->left = NULL;
        }

        preorder[preorder.size()-1]->left = NULL;
        preorder[preorder.size()-1]->right = NULL;
    }
};