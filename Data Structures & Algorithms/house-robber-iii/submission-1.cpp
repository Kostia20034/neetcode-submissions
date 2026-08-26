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
    int rob(TreeNode* root) {
        auto [skipRoot,robRoot] = dfs(root);
        return max(robRoot,skipRoot);
    }

    pair<int,int> dfs(TreeNode* root){
        if(root == nullptr) return {0,0};
        auto[leftSkip,leftPick] = dfs(root->left);
        auto[rightSkip,rightPick] = dfs(root->right);

        int robThis = root->val + leftSkip + rightSkip;
        int skipThis = max(leftSkip,leftPick) + max(rightSkip,rightPick);
        return {skipThis,robThis};
    }
};