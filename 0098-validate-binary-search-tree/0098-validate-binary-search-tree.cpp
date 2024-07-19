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
    void inorder(TreeNode* root, vector<int>& inorderTree)
    {
        if(!root) return;

        inorder(root->left, inorderTree);

        inorderTree.push_back(root->val);

        inorder(root->right, inorderTree);
    }
    bool isValidBST(TreeNode* root) {

        if(!root) return true;

        vector<int> inorderTree;
        inorder(root, inorderTree);

        for(int i=0; i<inorderTree.size()-1; i++)
        {
            if(inorderTree[i]>=inorderTree[i+1]) return false;
        }

        return true;
    }
};