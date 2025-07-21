class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        for(string s: tokens)
        {
            if(s == "+" || s =="-" || s=="*" || s == "/")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int ans;
                if(s=="+") ans = y+x;
                if(s=="-") ans = y-x;
                if(s=="*") ans = y*x;
                if(s=="/") ans = y/x;
                st.push(ans);
            }
            else
                st.push(stoi(s));
        }
        return st.top();
    }
};