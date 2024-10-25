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
 #include<climits>
 #include<algorithm>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;

        q.push({root,0});

        unsigned long long ans=0;

        while(!q.empty())
        {
            int levelSize = q.size();
            unsigned long long firstPos = q.front().second; // first node's position in the level
            unsigned long long lastPos = q.back().second;   // last node's position in the level
            ans = max(ans, lastPos - firstPos + 1); // width of current level
            
            for (int i = 0; i < levelSize; ++i) {
                auto [node, pos] = q.front();
                q.pop();
                
                // Adjust position relative to the first node in the level to prevent overflow
                unsigned long long newPos = pos - firstPos;
                if (node->left) {
                    q.push({node->left, 2 * newPos});
                }
                if (node->right) {
                    q.push({node->right, 2 * newPos + 1});
                }
            }
        }

        return ans;
    }
};