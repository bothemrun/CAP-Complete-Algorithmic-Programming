//[A] preprocessing

//1. add changeTime to the final tire without affecting the final time result, although we don't actually change it.

//2. then we can calculate the cost for each (tire i, laps).


//[B] 

//3. instead of traversing tires[] for i, we traverse numLaps for i
//4. we can calculate the best value given any consecutive lap.


//[C] complexity

//1. preprocessing laps=1~numLaps for each tire = O(n*1000) = 1e8 TLE.

//2. must exist some bound when the exponential power of the same tire is too much.

//3. instead of calculating the complex total time lie 1+r+r^2+r^3...,
//4. we only calculate 1 lap's cost: r^(x-1).
//5. extreme case: when 2^(x-1) = max_f*1 + changeTime ? 
//6.--> 2^(x-1) > 1e5*1 + 1e5 = 2e5 --> (x-1) >= 18 --> x >= 19 --> so 19 is the upper limit.


//O(preprocessing the best values for each lap) + O(Interval II DP on laps) =
//O(n * max lap for 1 tire) + O(numLaps * max lap for 1 tire) = O(19*(n + numLaps))

#define max_lap 19
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long changeTime;

    vector<long long> lap2mintime;//best value
    const long long EXCESS = LLONG_MAX;

    vector<long long> memo;
    const long long notyet = LLONG_MAX;

    long long partition(int i){
        if(i<0) return (-changeTime); //0;

        if(memo[i] != notyet) return memo[i];

        long long ret = EXCESS;
        for(int lap=1;lap<=max_lap;lap++){
            if(lap2mintime[lap] == EXCESS) break;

            int j = i - (lap-1);
            if(j<0) break;

            ret = min(
                ret,
                lap2mintime[lap] + partition(j-1) + changeTime
            );
        }
        return memo[i] = ret;
    }

    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        this->changeTime = changeTime;

        long long min_f = min_element(tires.begin(), tires.end())->at(0);
        lap2mintime.resize(max_lap+1, EXCESS);

        for(const vector<int>& t: tires){
            const long long f = t[0], r = t[1];
            long long sum = 0;
            long long p = 1;

            for(int lap=1;lap<=max_lap;lap++){
                if(f*p >= min_f + changeTime) break;

                sum += f*p;
                p *= r;

                lap2mintime[lap] = min(lap2mintime[lap], sum);
            }
        }

        memo.resize(numLaps, notyet);
        return partition(numLaps-1);
    }
};
