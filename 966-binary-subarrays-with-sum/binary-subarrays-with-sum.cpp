class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // prefix sum + hashing conept, also use in LC560
        // TC => O(n), SC => O(n)
        
        int n = nums.size();
        unordered_map<int ,int> prefixCount;
        prefixCount[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(prefixCount.find(sum - goal) != prefixCount.end())
                count = count + prefixCount[sum - goal];
            prefixCount[sum]++;
        }
        return count;


        //Best soln TC(O(2*2N)) SC(O(1))
        // int n = nums.size();
        // int l = 0, r = 0, prefixSum = 0, count = 0;
        // if(goal < 0) return 0;
        // while(r < n)
        // {
        //     prefixSum += nums[r];
        //     while(prefixSum > goal)
        //     {
        //         sum -= nums[l];
        //         l++;
        //     }
        //     count += (r-l+1);
        //     r = r + 1;
        // }

        // return numSubarraysWithSum(nums, goal) - numSubarraysWithSum(nums, goal - 1);
    }
};