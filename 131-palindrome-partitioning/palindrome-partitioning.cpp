class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end) if(s[start++]!=s[end--]) return false;
        return true;
    }

    void func(int ind,vector<vector<string>>& ans,vector<string> str,string s){
      if(ind==s.size()){
        ans.push_back(str);
        return;
      }

      for(int i=ind;i<s.size();i++){
        if(isPalindrome(s,ind,i)){
            str.push_back(s.substr(ind,i-ind+1));
            func(i+1,ans,str,s);
            str.pop_back();
        }
      }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> str;
        func(0,ans,str,s);
        return ans;
    }
};