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
    // 2 Stack iterative Approach
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> soln;
        if(root == NULL) return soln;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        while(st1.empty() == false)
        {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left != NULL)
                st1.push(node->left);
            if(node->right != NULL)
                st1.push(node->right);
        }
        while(st2.empty() == false)
        {
            TreeNode* node = st2.top();
            soln.push_back(node->val);
            st2.pop();
        }
        return soln;
    }



    // Recursive Approach
    // void post(TreeNode *root, vector<int> &soln)
    // {
    //     if(root == NULL) return;

    //     post(root->left, soln);
    //     post(root->right, soln);
    //     soln.push_back(root->val);
    // }

    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> soln;
    //     post(root, soln);
    //     return soln;
    // }
};