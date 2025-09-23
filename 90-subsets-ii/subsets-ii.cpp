class Solution {
public:
    void fn(int ind, vector<int> &ds, vector<int>& nums, vector<vector<int>> &soln)
    {
        soln.push_back(ds);
        for(int i=ind; i<nums.size(); i++)
        {
            if(i > ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            fn(i+1, ds, nums, soln);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> soln;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        fn(0, ds, nums, soln);
        return soln;
    }
};