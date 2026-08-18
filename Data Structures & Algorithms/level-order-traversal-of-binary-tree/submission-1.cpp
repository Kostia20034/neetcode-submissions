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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = q.size();
        vector<int> temp;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != nullptr) q.push(curr->right);
            cnt--;
            temp.push_back(curr->val);
            if(cnt == 0){
              res.push_back(temp);
              temp.clear();
              cnt = q.size();  
            } 
        }
        return res;

    }
};
