class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        //O(n) approach
        int low = 0, mid = 0, high = n-1;
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }

        // O(2N) approach:-
        /*
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
        */
    }
};