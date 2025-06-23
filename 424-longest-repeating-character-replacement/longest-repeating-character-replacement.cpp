class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0, r = 0, maxLen = 0, maxFreq = 0;
        unordered_map<char, int> count;
        while(r < n)
        {
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);
            // if we need to replace more than k charecters, shrink the window
            while((r-l+1) - maxFreq > k) 
            {
                count[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};