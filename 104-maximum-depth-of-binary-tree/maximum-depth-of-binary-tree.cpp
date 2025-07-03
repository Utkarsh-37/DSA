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
    // Iterative Soln
    int maxDepth(TreeNode* root)
    {
        if(root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false)
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
            depth++;
        }
        return depth;
    }

    //Recursive Solution
    // int maxDepth(TreeNode* root) {
    //     if(root == NULL) return 0;

    //     int lh = maxDepth(root->left);
    //     int rh = maxDepth(root->right);

    //     return 1+max(lh, rh);
    // }
};