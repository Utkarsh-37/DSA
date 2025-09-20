class Solution {
public:
    void fn(int ind, vector<int>& candidates, int target, vector<vector<int>> &soln, vector<int> &ds)
    {
        if(ind == candidates.size())
        {
            if(target == 0)
                soln.push_back(ds);
            return;
        }

        if(candidates[ind] <= target)
        {
            ds.push_back(candidates[ind]);
            fn(ind, candidates, target-candidates[ind], soln, ds);
            ds.pop_back();
        }
        fn(ind+1, candidates, target, soln, ds);       
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> soln;
        vector<int> ds;
        int sum = 0;
        fn(0, candidates, target, soln, ds);
        return soln;
    }
};