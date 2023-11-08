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
    void countGood(TreeNode* root, int &count, int currMax)
    {
        if(!root)return;

        if(root->val>=currMax)
        {
            count++;
            currMax=root->val;
        }

        countGood(root->left, count, currMax);
        countGood(root->right, count, currMax);
    }
    int goodNodes(TreeNode* root) {

        int count=0;

        countGood(root,count,INT_MIN);

        return count;
        
    }
};