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
    int goodNodes(TreeNode* root) {
        return good(root,root->val);
    }
    int good(TreeNode* root, int val){
        if(root == nullptr) return 0;
        if(root->val >= val){
            return 1 + good(root->left,root->val) + good(root->right, root->val);
        }
        return good(root->left,val) + good(root->right,val);
    }
};
