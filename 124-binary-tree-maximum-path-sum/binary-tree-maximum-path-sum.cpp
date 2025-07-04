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
    int maxP(TreeNode* root, int& maximum)
    {
        if(root == NULL) return 0;

        int leftsum = max(0, maxP(root->left, maximum));
        int rightsum = max(0, maxP(root->right, maximum));
        // we are using the max fn to ignore the paths that give us -ve sum

        maximum = max(maximum, leftsum + rightsum + root->val);
        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        maxP(root, maximum);
        return maximum;        
    }
};