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
    int dia(TreeNode* root, int& maximum)
    {
        if(root == NULL) return 0;
        int lh = dia(root->left, maximum);
        int rh = dia(root->right, maximum);

        maximum = max(maximum, lh+rh); 
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int maximum = 0;
        int sol = dia(root, maximum);
        return maximum;
    }
};