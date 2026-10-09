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
int balance(TreeNode *root){
            if (root==nullptr)
            return 0;
        int lh= balance(root->left);
            if(lh==-1)  return -1;
        int rh= balance(root->right);
            if (rh==-1)  return -1;
        if (abs(lh-rh)>1)   return -1;
        else    return max(lh,rh)+1;
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(balance(root)==-1)    return false;
         else return true;
    }
};
