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
    int count=0;
public:
    void counting(TreeNode *root, int seen){
        if (root==nullptr)  return;

        if (root->val>=seen){
            count++;
            seen= root->val;
        }
        counting(root->left, seen);
        counting(root->right, seen);

        
    } 
    int goodNodes(TreeNode* root) {
        counting(root, INT_MIN);
        return count;
    }
};
