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
    void post(TreeNode *root, vector<int> &soln)
    {
        if(root == NULL) return;

        post(root->left, soln);
        post(root->right, soln);
        soln.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> soln;
        post(root, soln);
        return soln;
    }
};