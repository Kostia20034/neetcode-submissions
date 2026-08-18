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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        else if(key < root->val) root->left = deleteNode(root->left,key);
        else if(key > root->val) root->right = deleteNode(root->right,key);
        else{
            if(root->left != nullptr && root->right != nullptr){
                TreeNode* successor = root->right;
                while(successor->left != nullptr){
                    successor = successor->left;
                }
                int vall = successor->val;
                root->right = deleteNode(root->right,vall);
                root->val = vall; 
            }
            else{
                TreeNode* temp = nullptr;
            if(root->left != nullptr) temp = root->left;
            else if(root->right != nullptr) temp = root->right;
            delete root;
            return temp;
            }
        }
        return root;
    }

};