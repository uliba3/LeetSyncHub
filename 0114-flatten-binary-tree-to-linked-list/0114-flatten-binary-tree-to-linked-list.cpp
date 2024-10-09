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
    void flatten(TreeNode* root) {
        if(root){
            TreeNode* rightNode = NULL;
            TreeNode* leftNode = NULL;
            if(root->right){
                rightNode = root->right;
                root->right = NULL;
                flatten(rightNode);
            }
            if(root->left){
                leftNode = root->left;
                root->left = NULL;
                flatten(leftNode);
                root->right = leftNode;
                while(root->right){
                    root = root->right;
                }
            }
            root->right = rightNode;
            root->left = NULL;
        }
    }
};