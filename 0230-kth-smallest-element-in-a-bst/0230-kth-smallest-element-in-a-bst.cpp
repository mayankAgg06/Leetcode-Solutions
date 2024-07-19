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
    void find(TreeNode* root, priority_queue<int>& pq)
    {
        if(!root) return;

        if(root->val < pq.top())
        {
            pq.pop();
            pq.push(root->val);
        }

        find(root->left,pq);
        find(root->right,pq);
    }
    int kthSmallest(TreeNode* root, int k) {

        priority_queue<int> pq;

        while(k--) pq.push(INT_MAX);

        find(root,pq);

        return pq.top();
        
    }
};