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
    TreeNode* prev=nullptr;
    int track=1;
public:
    void inorder(TreeNode *root){
        
        if (root==nullptr)  return;

      inorder(root->left);
        if (prev!=nullptr && prev->val>=root->val) track=0;
        prev=root;
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {

        inorder(root);
        if (track==1)   return true;
        else    return false;
    }
};
