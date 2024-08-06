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
    
    TreeNode* make(vector<int>& preorder, vector<int>& inorder, int prestart, int preend,int instart, int inend, map<int,int> &mp)
    {
        if(prestart>preend || instart>inend)return NULL;

        TreeNode* root= new TreeNode(preorder[prestart]);

        int inroot= mp[preorder[prestart]];
        int nums= inroot-instart;

        root->left= make(preorder,inorder,prestart+1, prestart+nums,instart,inroot-1,mp);
        root->right= make(preorder,inorder,prestart+nums+1,preend,inroot+1,inend,mp);

        return root;
    }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(inorder.size()!=preorder.size() || inorder.size()==0)return NULL;

        map<int,int> mpp;

        for(int i=0; i<inorder.size(); i++)
        {
            mpp[inorder[i]]=i;
        }
        
        return make(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mpp);
        
    }
};