class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vow = {'a','e','i','o','u','A','E','I','O','U'};
        vector<char> extractedVowels;
        
        for(char c : s)
        {
            if(vow.count(c))
                extractedVowels.push_back(c);
        }

        sort(extractedVowels.begin(), extractedVowels.end());

        string soln = "";
        int ind = 0;
        for(char c : s)
        {
            if(vow.count(c))
                soln += extractedVowels[ind++];
            else 
                soln += c;
        }
        return soln;        
    }
};