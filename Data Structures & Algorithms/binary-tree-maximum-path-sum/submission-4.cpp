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
    int maxPathSum(TreeNode* root) {
        int mac = INT_MIN;
        pathSum(root,mac);
        return mac;

    }
    int pathSum(TreeNode * root, int& mac){
        if(root == nullptr) return 0;
        int left = pathSum(root->left,mac);
        int right = pathSum(root->right,mac);
        if(left < 0) left = 0;
        if(right < 0 ) right = 0;
        mac = max(mac, root->val + left + right);
        int maxLeaf = max(left,right);
        return root->val + maxLeaf;
    }
};
