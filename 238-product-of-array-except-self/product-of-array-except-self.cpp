class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int num = 1;
        int cnt_zero = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
                cnt_zero++;
            else
                num = num*nums[i];
        }
        vector<int> soln;
        for(int i=0; i<n; i++)
        {
            if(cnt_zero == 1)
            {
                if(nums[i] == 0)
                    soln.push_back(num);
                else
                    soln.push_back(0);
            }
            else if(cnt_zero > 1)
                soln.push_back(0);
            else
                soln.push_back(num/nums[i]);
        }
        

        return soln;
    }
};