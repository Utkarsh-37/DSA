class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // think of the qs as max len subarr with at most k zeroes
        int n = nums.size();
        int zeroes = 0, maxLen = 0, l = 0, r = 0;
        int lastZeroIndex = -1;
        while(r<n)
        {
            if(nums[r] == 0)
            {
                zeroes++;
            }
            while(zeroes > k)
            {
                if(nums[l]==0)
                    zeroes--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
            
        }
        return maxLen;
    }
};