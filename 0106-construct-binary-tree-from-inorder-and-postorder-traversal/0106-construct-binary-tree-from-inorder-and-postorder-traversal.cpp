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
    TreeNode* building(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd)
    {
        if(inStart>inEnd || postStart> postEnd)return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = help[postorder[postEnd]];
        int nums = inEnd-inRoot;

        root->right = building(inorder,postorder,inRoot+1,inEnd,postEnd-nums,postEnd-1);
        root->left = building(inorder,postorder,inStart,inRoot-1,postStart,postEnd-nums-1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for(int i=0; i<inorder.size(); i++) help[inorder[i]]=i;

        return building(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
        
    }
};