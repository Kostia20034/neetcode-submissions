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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* result = nullptr;
        int count = 0;
        kth(root,k,count,result);
        return result == nullptr ? 0 : result->val;
    }

    void kth(TreeNode* root, int k, int& cnt, TreeNode*& result){
        if(root == nullptr || result != nullptr) return;
        kth(root->left,k,cnt,result);
        cnt = cnt + 1;
        if(cnt == k){
            result = root;
            return;
        }
        kth(root->right,k,cnt,result);
    }
};
