class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int low = 1, high = piles[n-1];
        int ans = 1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            long long sol = 0;
            for(int i=0; i<n; i++)
            {
                if(piles[i]%mid == 0)
                    sol += (piles[i]/mid);
                else
                    sol += ((piles[i]/mid)+1);
                
            }
            if(sol > h)
                low = mid + 1;
            if(sol <= h)
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};