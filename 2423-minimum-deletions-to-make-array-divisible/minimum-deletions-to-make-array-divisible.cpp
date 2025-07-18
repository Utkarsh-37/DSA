class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n = nums.size();
        int m = numsDivide.size();
        sort(nums.begin(),nums.end());
        int gcd = -1;
        for(int i=0; i<n; i++)
        {
            int len = m; 
            while(len>0)
            {
                if(numsDivide[len-1]%nums[i]==0)
                {
                    len--;
                    continue;
                }    
                break;
            }
            
            if(len==0)
            {
                gcd = nums[i];
                break;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(nums[i]==gcd)
                return i;
        }
        return -1;
    }
};