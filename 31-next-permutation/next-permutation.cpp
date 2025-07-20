class Solution {
public:
    void reverse(vector<int>& nums, int a, int n)
    {
        int low = a;
        int high = n-1;
        while(low < high)
        {
            swap(nums, low, high);
            low++;
            high--;
        }
    }

    void swap(vector<int>& nums, int a, int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int brk_pt = -1;
        int switch_pt = -1;

        for(int i=n-2; i>=0; i--)
        {
            if(nums[i+1] > nums[i])
            {
                brk_pt = i;
                break;
            }
        }
        if(brk_pt == -1)
        {
            reverse(nums, 0 ,n);
            return;
        }
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i] > nums[brk_pt])
            {
                switch_pt = i;
                break;
            }
        }

        swap(nums, brk_pt, switch_pt);
        reverse(nums, brk_pt+1, n);
    }
};