//the same as 2008	Maximum Earnings From Taxi	medium, but easier.

//[A] weighted interval scheduling

//1. actually for interval scheduling with weight=1, using DP over greedy (both ok) is more consistent.


//[B] jump table

//[C] O(sort + binary search) + O(dp) = O(mlogm + m)

#define interval offers
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int m;
    vector<int> jump;

    const int notyet = (-1);
    vector<int> memo; //no overflow
    int choose_skip_jump(const vector<vector<int>>& interval, int i){
        if(i==m) return 0;

        if(memo[i] != notyet) return memo[i];

        //choose or skip
        return memo[i] = max(
            choose_skip_jump(interval, i+1),
            choose_skip_jump(interval, jump[i]) + interval[i][2]
        );
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        //standard weighted interval scheduling
        this->m = interval.size();
        //the only matters is the start.
        sort(interval.begin(), interval.end());

        //jump table
        jump.resize(m);
        for(int i=0;i<m;i++){
            jump[i] = lower_bound(
                interval.begin(),
                interval.end(),
                vector<int>({
                    interval[i][1] + 1,
                    INT_MIN,
                    INT_MIN
                })
            ) - interval.begin();
        }

        //weighted interval scheduling
        memo.resize(m, notyet);
        return choose_skip_jump(interval, 0);
    }
};
