class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtracking(0, 0, "", n, result);
        return result;
    }

    void backtracking(int openedCount, int closedCount, string str, int n, vector<string>& result) {

        if(str.length() == 2*n)
        {
            result.push_back(str);
            return ;
        }

        if(openedCount < n)
        {
            backtracking(openedCount+1, closedCount, str + "(", n, result);
        }

        if(openedCount > closedCount)
        {
            backtracking(openedCount, closedCount+1, str + ")", n, result);
        }
    }
};