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
    unordered_map<int,int> help;
    TreeNode* build(vector<int> preorder, vector<int> inorder, int inStart, int inEnd, int preStart, int preEnd)
    {
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = help[preorder[preStart]];
        int nums = inRoot - inStart;

        root->left = build(preorder,inorder,inStart,inRoot-1,preStart+1,preStart+nums);
        root->right = build(preorder,inorder,inRoot+1,inEnd,preStart+nums+1,preEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for(int i=0; i<inorder.size(); i++)
        {
            help[inorder[i]]=i;
        }

        return build(preorder,inorder,0,inorder.size()-1,0,preorder.size()-1);
        
    }
};