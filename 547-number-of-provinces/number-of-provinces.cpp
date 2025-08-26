class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjL, vector<int> &vis)
    {
        vis[node] = 1;
        for(int it : adjL[node])
        {
            if(vis[it] == 0)
                dfs(it, adjL, vis);
        }

    }
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
        // Creating adj list (will use in dfs, can use matrix too)
        vector<vector<int>> adjL(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n, 0);
        int soln = 0;
        for(int i=0; i<n; i++)
        {
            if(vis[i] == 0)
            {
                soln++;
                //bfs(i, isConnected, vis);
                dfs(i, adjL, vis);
            }
        }
        

        return soln;
    }
};