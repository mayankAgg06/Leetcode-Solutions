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
    TreeNode* create(vector<int> preorder)
    {
        if(preorder.size()==0)return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        vector<int> leftArr,rightArr;

        for(int i=1; i<preorder.size(); i++)
        {
            if(preorder[i]>root->val) rightArr.push_back(preorder[i]);

            else leftArr.push_back(preorder[i]);
        }

        root->left = create(leftArr);
        root->right = create(rightArr);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return create(preorder);
    }
};