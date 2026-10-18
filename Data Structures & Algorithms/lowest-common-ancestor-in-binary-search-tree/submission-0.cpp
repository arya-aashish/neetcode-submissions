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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr)  return root;

        if (root->val==p->val|| root->val==q->val)  return root;

        TreeNode *lca1= lowestCommonAncestor(root->left, p, q);
        TreeNode *lca2= lowestCommonAncestor(root->right, p,q);

        if (lca1!=nullptr && lca2!=nullptr) return root;

        if (lca1!=nullptr)  return lca1;
        else return lca2;
    }
};
