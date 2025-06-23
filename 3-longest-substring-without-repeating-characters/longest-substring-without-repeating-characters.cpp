class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int start = 0;
        int end = 0;
        int maxLen = min(1, n);
        unordered_set<char> st;
        while(end<n)
        {
            char c = s[end];
            while(st.find(c)!= st.end())
            {
                st.erase(s[start]);
                start++;
            }
            st.insert(c);
            maxLen = max(maxLen, (end-start+1));
            end++;
        }
        return maxLen;





        //Approach 2 using hashing
        /*
        int n = s.length();
        vector<int> hash(255, -1);
        int l = 0, r = 0;
        int maxLen = 0;
        while(r<n)
        {
            if(hash[s[r]] != -1)
            {
                if(hash[s[r]] >= l)
                    l = hash[s[r]] + 1;
            }
            maxLen = max(maxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
        */

    }
};