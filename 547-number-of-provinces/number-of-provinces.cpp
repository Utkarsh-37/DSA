class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<int> &vis)
    {
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(q.empty() == false)
        {
            int front = q.front();
            q.pop();
            for(int j=0; j<isConnected.size(); j++)
            {
                if(isConnected[front][j] == 1 && vis[j] == 0)
                {
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int soln = 0;
        for(int i=0; i<n; i++)
        {
            if(vis[i] == 0)
            {
                soln++;
                bfs(i, isConnected, vis);
            }
        }
        return soln;
    }
};