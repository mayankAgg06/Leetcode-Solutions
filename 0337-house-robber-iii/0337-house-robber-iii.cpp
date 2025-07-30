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
    std::unordered_map<TreeNode*, std::pair<int, int>> memo;

    std::pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }

        if (memo.count(node)) {
            return memo[node];
        }

        std::pair<int, int> left_res = dfs(node->left);
        std::pair<int, int> right_res = dfs(node->right);

        int current_not_robbed = std::max(left_res.first, left_res.second) +
                                 std::max(right_res.first, right_res.second);

        int current_robbed = node->val + left_res.first + right_res.first;

        return memo[node] = {current_not_robbed, current_robbed};
    }

    int rob(TreeNode* root) {
        std::pair<int, int> final_res = dfs(root);
        return std::max(final_res.first, final_res.second);
    }
};