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
    int find(TreeNode* root, int &result)
    {
        if(!root)return 0;

        int left = find(root->left,result);
        int right = find(root->right,result);

        result = max(result,left+right);

        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int result = 0;
        find(root,result);

        return result;
    }
};