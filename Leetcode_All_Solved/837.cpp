//m0
//recursion with memo.  to avoid O(n * maxPts) TLE, use prefix sum.
#define notyet (-1)
#include<assert.h>
#include<algorithm>

class Solution {
public:
    int k, maxPts;
    //NOTE: memo[j] != prefix[j] - prefix[j-1]
    //'cuz prefix has clipping for >= k
    vector<double> memo;
    vector<double> prefix;

    inline double range_sum_clipping(const int& i, int j, const int& clipping){
        j = min(j, clipping - 1);

        if(!(i <= j)) return 0;
        if(j < 0) return 0;

        return (i <= 0)? prefix[j]:( prefix[j] - prefix[i-1] );
    }

    double draw_prefix(const int& point){
        if(point < 0) return 0;

        //NOTE: memo & prefix simultaneously ready
        if(memo[point] != notyet) return memo[point];

        if(point == 0){
            prefix[0] = 1;
            return memo[0] = 1;
        }

        //NOTE: make previous prefix ready
        draw_prefix(point - 1);

        memo[point] = range_sum_clipping(
            point - maxPts,
            point - 1,
            k
        ) / (double)maxPts;

        assert(point-1 >= 0);
        prefix[point] = prefix[point-1] + memo[point];

        return memo[point];
    }
    double new21Game(int n, int k, int maxPts) {
        this->k = k;
        this->maxPts = maxPts;

        //NOTE: both simultaneously ready.
        memo.resize(n+1, notyet);
        prefix.resize(n+1);

        double prob = 0;
        assert(k <= n);
        //NOTE: stop drawing after >= k, so the iterations are independent.
        for(int point=k;point<=n;point++)
            prob += draw_prefix(point);
        return prob;
    }
};
