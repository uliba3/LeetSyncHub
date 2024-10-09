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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0){
            return nullptr;
        }
        int m = postorder[postorder.size()-1];
        vector<int> rightTreeInorder, rightTreePostorder, leftTreeInorder, leftTreePostorder;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i]==m){
                break;
            }
            leftTreeInorder.push_back(inorder[i]);
            leftTreePostorder.push_back(postorder[i]);
        }
        for(int i = leftTreeInorder.size(); i < inorder.size()-1; i++){
            rightTreeInorder.push_back(inorder[i+1]);
            rightTreePostorder.push_back(postorder[i]);
        }
        TreeNode* t = new TreeNode(m);
        t->left = buildTree(leftTreeInorder, leftTreePostorder);
        t->right = buildTree(rightTreeInorder, rightTreePostorder);
        return t;
    }
};