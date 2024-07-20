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
    bool ans = false;
    bool isSame(TreeNode* root, TreeNode* subRoot)
    {
        if(!root and !subRoot) return true;
        if(!root || !subRoot) return false;

        return (root->val==subRoot->val and isSame(root->left,subRoot->left) and isSame(root->right,subRoot->right));
    }
    void traversal(TreeNode* root, TreeNode* subRoot)
    {
        if(!root) return;

        if(root->val==subRoot->val and isSame(root,subRoot)) ans=true;

        traversal(root->left, subRoot);
        traversal(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        traversal(root,subRoot);
        return ans;
    }
};