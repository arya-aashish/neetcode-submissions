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
int preIndex=0;
public:
    TreeNode *con (vector<int> &preorder, vector<int> &inorder, int is, int ie){
        if (is>ie) return nullptr;
        TreeNode *root= new TreeNode (preorder[preIndex++]);
        int up;
        for (int i=is; i<ie; i++){
            if (inorder[i]==root->val){
                up=i;
                break;
            }
        }

        root->left= con(preorder, inorder, is, up-1);
        root->right=con(preorder, inorder, up+1, ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root=con(preorder, inorder, 0, inorder.size()-1);
        return root;
    }
};
