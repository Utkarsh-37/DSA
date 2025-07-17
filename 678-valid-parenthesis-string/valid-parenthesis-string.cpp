class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int low = 0, high = 0;
        // low = min no. of open brackets possible
        // high = max no. of open brackets possible
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                low ++;
                high++;
            }
            if(s[i]==')')
            {
                low--;
                high--;
            }
            if(s[i]=='*')
            {
                low--;
                high++;
            }
            if(high < 0) return false;
            if(low < 0) low = 0;
        }
        if(low == 0)
            return true;
        return false;        
    }
};