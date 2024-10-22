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
class BSTIterator {
public:
    vector<int> inorder;
    int itr=0;

    void in(TreeNode* root)
    {
        if(!root)return;

        in(root->left);
        inorder.push_back(root->val);
        in(root->right);
    }

    BSTIterator(TreeNode* root) {
        inorder.push_back(INT_MIN);
        in(root);
    }
    
    int next() {
        itr++;
        return inorder[itr];
    }
    
    bool hasNext() {
        return itr+1<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */