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
private:
    bool checkSymmetric(TreeNode* l, TreeNode* r) {
        if(l==nullptr&&r==nullptr){
            return true;
        }else if(l == nullptr && r != nullptr){
            return false;
        }else if(l != nullptr && r == nullptr){
            return false;
        }
        if(l->val!=r->val){
            return false;
        }
        return checkSymmetric(l->left, r->right) && checkSymmetric(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root->left, root->right);
    }
};