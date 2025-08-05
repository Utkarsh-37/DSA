class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int n = boxes.length();
        int current;
        for (int i = 0; i < n; i++) {
            current = 0;
            for (int j = 0; j < n ; j++) {
                if (boxes[j] == '1') 
                    current += abs(j - i);
            }
            ans.push_back(current);
        }
        return ans;
    }
};