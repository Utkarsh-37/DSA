class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        if(m > n/k)             //m*n>k
            return -1;

        int high = INT_MIN;
        int low = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(bloomDay[i]>=high)
                high = bloomDay[i];
            if(bloomDay[i] < low)
                low = bloomDay[i];
        }

        int ans = 0;
        while(low <= high)
        {
            int mid = (low+high)/2;
            int count = 0;
            int sum = 0;
            for(int i=0; i<n; i++)
            {
                if(mid >= bloomDay[i])
                {
                    count++;
                    if(count == k)
                    {
                        sum++;
                        count = 0;
                    }
                }
                else
                    count = 0;
            }

            if(sum >= m)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;

        }
        
        return ans;
    }
};