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
vector <int> res;
int maxlevel=0;
public: 
    void rightSide(TreeNode *root, int level){

        if (root==nullptr)  return;
        if (maxlevel<level){
            res.push_back(root->val);
            maxlevel++;
    }
    rightSide (root->right, level+1);
    rightSide (root->left, level+1);
}
    vector<int> rightSideView(TreeNode* root) {
        rightSide(root, 1);
        return res;
    }
};
