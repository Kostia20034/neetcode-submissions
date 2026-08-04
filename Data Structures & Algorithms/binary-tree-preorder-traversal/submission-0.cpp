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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        treeTraversal(res,root);
        return res;
    }
    void treeTraversal(vector<int> &res, TreeNode* root){
        if(root == nullptr) return;
        res.push_back(root->val);
        treeTraversal(res,root->left);
        treeTraversal(res,root->right);
    }
};