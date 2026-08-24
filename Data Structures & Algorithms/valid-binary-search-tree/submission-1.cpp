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
    bool isValidBST(TreeNode* root) {
        return isBST(root,INT_MIN,INT_MAX);
    }
    bool isBST(TreeNode* root, int lower, int upper){
        if(root == nullptr) return true;
        if(root->val > lower && root->val < upper){
            return isBST(root->left,lower,root->val) &&
            isBST(root->right,root->val,upper);
        }
        return false;
    }
};
