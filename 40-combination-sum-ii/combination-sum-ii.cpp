class Solution {
public:
    void fn(int ind, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& soln)
    {
        if(target == 0)
        {
            soln.push_back(ds);
            return;
        }
        for(int i=ind; i<candidates.size(); i++)
        {
            if(i>ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            fn(i+1, candidates, target-candidates[i], ds, soln);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> soln;
        vector<int> ds;
        fn(0, candidates, target, ds, soln);
        return soln;
    }
};