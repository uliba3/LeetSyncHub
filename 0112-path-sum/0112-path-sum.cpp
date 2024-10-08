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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        cout << root->val << endl;
        if(root->val==targetSum && !root->left && !root->right){
            return true;
        }else{
            targetSum -= root->val;
            if(hasPathSum(root->left, targetSum)){
                return true;
            }
            if(hasPathSum(root->right, targetSum)){
                return true;
            }
        }
        return false;
    }
};