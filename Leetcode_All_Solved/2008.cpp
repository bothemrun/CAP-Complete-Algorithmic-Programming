//[A] weighted interval scheduling

//1. actually for interval scheduling with weight=1, using DP over greedy (both ok) is more consistent.


//[B] jump table

//[C] O(sort + binary search) + O(dp) = O(mlogm + m)

#define tiil tuple<int,int,long long>
#include<tuple>
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
    vector<tiil> interval;

    const long long notyet = (-1);
    vector<long long> memo;
    long long choose_skip_jump(int i){
        if(i==m) return 0;

        if(memo[i] != notyet) return memo[i];

        //1. skip or choose then jump
        return memo[i] = max(
            choose_skip_jump(i+1),
            choose_skip_jump(jump[i]) + get<2>( interval[i] )
        );
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        //standardize for the weighted interval scheduling
        this->m = rides.size();

        interval.resize(m);
        for(int i=0;i<m;i++){
            interval[i] = tiil(
                rides[i][0],
                rides[i][1],
                (long long)(rides[i][1] - rides[i][0] ) + (long long)rides[i][2]
            );
        }

        //the only order that matters is the start.
        sort(interval.begin(), interval.end());

        //jump table
        jump.resize(m);
        for(int i=0;i<m;i++){
            int j = lower_bound(
                interval.begin(),
                interval.end(),
                tiil(
                    get<1>( interval[i] ),
                    LLONG_MIN,
                    LLONG_MIN
                )
            ) - interval.begin();

            jump[i] = j;
        }


        //weighted interval scheduling
        memo.resize(m, notyet);
        return choose_skip_jump(0);
    }
};
