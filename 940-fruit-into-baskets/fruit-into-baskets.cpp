class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // imp to revise map 
        // O(N) soln => most optimal
        int n = fruits.size();
        int l = 0, maxLen = 0;
        unordered_map<int, int> count;

        for(int r=0; r<n; r++)
        {
            count[fruits[r]]++;
            if(count.size() > 2)
            {
                count[fruits[l]]--;
                if(count[fruits[l]] == 0)
                    count.erase(fruits[l]);
                l++;
            }
            if(count.size() <=2)
                maxLen = max(maxLen, r-l+1);
        }
        return maxLen;

        // O(N+N) soln (good enough in most cases)
        /*
        int n = fruits.size();
        int l = 0, maxLen = 0;
        unordered_map<int, int> count;

        for(int r=0; r<n; r++)
        {
            count[fruits[r]]++;
            while(count.size() > 2)
            {
                count[fruits[l]]--;
                if(count[fruits[l]] == 0)
                    count.erase(fruits[l]);
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
        */
    }
};