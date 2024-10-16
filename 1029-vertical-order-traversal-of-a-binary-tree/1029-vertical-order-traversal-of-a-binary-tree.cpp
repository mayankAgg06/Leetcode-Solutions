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

    void iterateTree(TreeNode* root, map<int,map<int,multiset<int>>> &helper, int row,int col)
    {
        if(!root) return;

        helper[row][col].insert(root->val);

        if(root->left) iterateTree(root->left,helper,row-1,col+1);

        if(root->right) iterateTree(root->right, helper,row+1,col+1);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int,map<int,multiset<int>>> helper;

        iterateTree(root,helper,0,0);

        vector<vector<int>> solution;

        for(auto itr:helper)
        {
            vector<int> each;
            for(auto level:itr.second)
            {
                for(auto ele:level.second) each.push_back(ele);
            }
            solution.push_back(each);
        }

        return solution;
        
    }
};