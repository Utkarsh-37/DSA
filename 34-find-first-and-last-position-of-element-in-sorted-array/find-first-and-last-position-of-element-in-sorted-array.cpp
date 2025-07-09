class Solution {
public:
    int lb(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = n, ub = n;
        // code for lb
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] >= target)
            {
                ans = mid;
                high = mid -1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

    int ub(vector<int>& nums, int target)
    {
        int n = nums.size();
        int low = 0, high = n-1;
        int ans = n, ub = n;
        // code for ub
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] > target)
            {
                ans = mid;
                high = mid -1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = lb(nums, target);
        if(left == n || nums[left] != target)
            return {-1, -1};
        int right = ub(nums, target);
        return {left, right-1};

    }
};