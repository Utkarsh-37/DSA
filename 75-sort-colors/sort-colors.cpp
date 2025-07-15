class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red = 0;
        int blue = 0;
        int white = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
                red++;
            else if(nums[i]==1)
                white++;
            else
                blue++;
        }
        int index = 0;
        for(int i=0; i<red; i++)
        {
            nums[index] = 0;
            index++;
        }
        for(int i=0; i<white; i++)
        {
            nums[index] = 1;
            index++;
        }
        for(int i=0; i<blue; i++)
        {
            nums[index] = 2;
            index++;
        }
    }
};