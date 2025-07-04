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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if(root == NULL) return zigzag;

        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(q.empty() == false)
        {
            int size = q.size();
            vector<int> soln;
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) 
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                soln.push_back(node->val);
            }
            if(count%2 == 0)
                zigzag.push_back(soln);
            else
            {
                reverse(soln.begin(), soln.end());
                zigzag.push_back(soln);
            }
            count++;
        }
        return zigzag;
    }
};