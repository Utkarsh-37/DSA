class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int n = groupSizes.size();
        vector<vector<int>> groups(n+1); 
        for (int i = 0; i < n; i++) {
            groups[groupSizes[i]].push_back(i);
        }

        for (int i = 1; i < n+1; i++) {
            vector<int> current = {};
            for (int j = 0; j < groups[i].size(); j++) {
                current.push_back(groups[i][j]);
                if (current.size() == i) {
                    ans.push_back(current);
                    current = {};
                }
            }
        }

        return ans;
    }
};