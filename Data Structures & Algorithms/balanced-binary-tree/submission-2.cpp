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
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        maxDepth(root,flag);
        return flag;
    }
    int maxDepth(TreeNode* root, bool& flag) {
        if(!flag) return 10000;
        if(root == nullptr){
            return 0;
        }
        int left = maxDepth(root->right,flag);
        int right = maxDepth(root->left,flag);
        if(abs(left - right) > 1){
            flag = false;
        }
        return 1 + max(left,right);
    }
};
