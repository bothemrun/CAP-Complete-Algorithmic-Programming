//[A] Naive / Brute Force First: 

//1. partition dp
//2. dp(i, part) for k parts: O(n*n*k)
//3. for 1~n parts: TLE...


//[B] Reverse Thinking From Results:

//1. don't think of them as partition,
//2. think of them from the results --> putting signs in fromt of nums.


//[C] Reverse Thinking From Results:

//1. no consecutive negative signs, but ok with consecutive positive signs
 

//[D] dp(i, bool ban_negative)
//1. wisdompeak Basic DP I --> O(n)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const long long notyet = LLONG_MIN;
    vector<vector<long long>> memo;

    long long enum2(const vector<int>& nums, int i, bool ban_negative){
        //if(i<0) return 0;
        //trap: (1) length 1 array. (2) front
        if(i==0) return nums[0];
        

        if(memo[i][ban_negative] != notyet) return memo[i][ban_negative];

        long long ret = nums[i] + enum2(nums, i-1, false);

        if(ban_negative == false){
            ret = max(
                ret,
                -nums[i] + enum2(nums, i-1, true)
            );
        }

        return memo[i][ban_negative] = ret;
    }

    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, vector<long long>(2, notyet));

        return enum2(nums, n-1, false);
    }
};
