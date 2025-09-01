class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,int>> pq;
        
        for(int i=0; i<n; i++){
            double cpr = prGain(classes[i][0],classes[i][1]);
            pq.push({cpr,i});
        }
        
        while(extraStudents){
            int i = pq.top().second;
            pq.pop();
            classes[i][0] += 1;
            classes[i][1] += 1;
            
            double cpr = prGain(classes[i][0],classes[i][1]);
            pq.push({cpr,i});
            extraStudents--;
        }
        
        double res = 0;
        for(int i=0; i<n; i++){
            res += double(classes[i][0])/classes[i][1];
        }
        return res/n;
    }
    double prGain(int pass, int total) {
        // (p+1)/(t+1) - p/t = (t - p) / (t * (t + 1))
        return double(total - pass) / (double(total) * double(total + 1));
    }
};