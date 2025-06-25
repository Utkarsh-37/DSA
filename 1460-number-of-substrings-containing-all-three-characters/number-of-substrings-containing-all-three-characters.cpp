class Solution {
public:
//1 + min of all 3 indexes will give all possible substr before the smallest window which contains all 3 char, we do it for all smallest wondows and get all substrs   
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;
        vector<int> mpp(3, -1);

        for(int i=0; i<n; i++)
        {
            mpp[s[i]-'a'] = i;
            if(mpp[0] != -1 && mpp[1] != -1 && mpp[2] != -1)
                count += 1 + min(mpp[0],min(mpp[1], mpp[2]));    
        }
        return count;
    }
};