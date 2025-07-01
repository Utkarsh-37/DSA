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
    void inorder(TreeNode *root, vector<int> &soln)
    {
        if(root == NULL) return;
        inorder(root->left, soln);
        soln.push_back(root->val);
        inorder(root->right, soln);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> soln;
        inorder(root, soln);
        return soln;
    }
};