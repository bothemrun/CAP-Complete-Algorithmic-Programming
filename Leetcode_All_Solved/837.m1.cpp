//m1
//bottom up dp.

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        double maxPts_double = (double)maxPts;
        vector<double> memo(n+1);
        
        memo[0] = 1;
        double window_sum = 1;

        //NOTE: edge case
        if(n == 0 || k == 0) return 1;
        
        double prob = 0;
        for(int point=1;point<=n;point++){
            memo[point] = window_sum / maxPts_double;

            if(k <= point) prob += memo[point];

            //update
            if(point < k) window_sum += memo[point];

            //remove
            int window_left = point - maxPts;
            if(0<=window_left && window_left<k)
                window_sum -= memo[window_left];
        }

        return prob;
    }
};
