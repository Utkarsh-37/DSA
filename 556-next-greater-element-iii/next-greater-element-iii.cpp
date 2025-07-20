class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int sz = s.size();
        int brk_pt = -1, switch_pt = -1;

        for (int i = sz - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                brk_pt = i;
                break;
            }
        }

        if (brk_pt == -1)
            return -1; 

        for (int i = sz - 1; i > brk_pt; i--) {
            if (s[i] > s[brk_pt]) {
                switch_pt = i;
                break;
            }
        }

        swap(s[brk_pt], s[switch_pt]);
        reverse(s.begin() + brk_pt + 1, s.end());
        
        int i = sz-1;
        long long soln = 0;
        int pw = 0;
        while(i>=0)
        {
            int x = s[i]-'0';
            soln += x*pow(10, pw);
            pw++;
            i--;
        }
        if(soln > INT_MAX)
            return -1;
        return soln;
    }
};