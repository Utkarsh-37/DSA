class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // think of it as prev qs and assume even nos as 0 and odd as 1
        // the qs then becomes find no. of subarr with sum = k

        int n = nums.size();
        int sum = 0, count = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        for(int i=0; i<n; i++)
        {
            if(nums[i]%2 != 0)
                sum += 1;
            if(prefixSum.find(sum - k) != prefixSum.end())
                count += prefixSum[sum-k];
            prefixSum[sum]++;
        } 
        return count;
    }
};