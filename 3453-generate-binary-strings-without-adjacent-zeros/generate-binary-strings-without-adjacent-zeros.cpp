class Solution {
public:
    void f(string s, int n, vector<string>&ans){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        f(s+'1', n, ans);
        if(s.empty() || s.back()!='0')
            f(s+'0', n, ans);
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        f("" , n , ans);   
        return ans;
    }
};