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
    void inorder(vector<int> &in, TreeNode* root)
    {
        if(!root) return;

        inorder(in,root->left);
        in.push_back(root->val);
        inorder(in,root->right);
    }

    bool isMirror(TreeNode* lRoot, TreeNode* rRoot)
    {
        if(!lRoot and !rRoot) return true;
        if(!lRoot || !rRoot) return false;

        bool left = isMirror(lRoot->left,rRoot->right);
        bool right = isMirror(lRoot->right,rRoot->left);

        if(left and right) return lRoot->val==rRoot->val;

        return false;

    }
    bool isSymmetric(TreeNode* root) {
        
        if(!root || (!root->left and !root->right))return true;

        if(!root->left || !root->right) return false;

        // vector<int> inOrd, rev;
        // inorder(inOrd,root);

        // rev = inOrd;
        // reverse(inOrd.begin(),inOrd.end());

        // return rev==inOrd;

        return isMirror(root->left,root->right);

    }
};