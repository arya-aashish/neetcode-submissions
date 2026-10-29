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
    int counter=0;
    int res=-1;
public:
    void search(TreeNode *root, int k){
        if (root==nullptr)  return;

        search(root->left, k);
        counter++;
        if (counter==k){
            res=root->val;
            return;
        }
        search(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        search(root, k);
        return res;
    }
};
