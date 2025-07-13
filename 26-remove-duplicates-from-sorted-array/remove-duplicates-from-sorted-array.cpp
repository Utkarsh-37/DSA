class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int index = 1;
        for(int i=1; i<n; i++)
        {
            if(nums[i]>nums[i-1])
            {
                count++;
                nums[index] = nums[i];
                index++;
            }
            
        }
        if(count==0)
            return 1;
        
        return count;
    }
};