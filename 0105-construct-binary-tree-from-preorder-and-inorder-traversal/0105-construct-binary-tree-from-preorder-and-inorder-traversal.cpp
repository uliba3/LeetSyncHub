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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0){
            return nullptr;
        }
        TreeNode* t = new TreeNode(preorder[0]);
        int leftTreeSize = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        cout << "leftTreeSize" << leftTreeSize << endl;
        vector<int> inorderLeftTree, preorderLeftTree;
        for(int i = 0; i < leftTreeSize; i++){
            inorderLeftTree.push_back(inorder[i]);
            preorderLeftTree.push_back(preorder[i+1]);
        }
        t->left = buildTree(preorderLeftTree, inorderLeftTree);

        int rightTreeSize = preorder.size() - leftTreeSize - 1;
        vector<int> inorderRightTree, preorderRightTree;
        for(int i = 0; i < rightTreeSize; i++){
            inorderRightTree.push_back(inorder[i+1+leftTreeSize]);
            preorderRightTree.push_back(preorder[i+1+leftTreeSize]);
        }
        t->right = buildTree(preorderRightTree, inorderRightTree);

        return t;
    }
};