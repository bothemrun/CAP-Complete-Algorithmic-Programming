//m0

//[A] turn the 4-variable float point into a 2-variable integer problem.

//1. conditions: if x/a == y/b,
//2. then x/a == (total-x)/(n-a),
//3. turn division into integer: x*(n-a) == (total-x)*a
//4. so it's a 2-variable condition for (x, a), instead of (x, a, y, b)


//[B] brute force enum?

//1. subset problem --> O(2^n)
//2. turned into a knapsack problem with O(n * n * total_sum)


//[C] pruning

//1. if x > total_sum/2, then break.
//2. assume a <= b
//3. O(max_nums*n/2 * n/2 * n) = 1e4 / 4 * 30^3 = 6.75e7  --> probably TLE.

class Solution {
public:
    int total_sum;
    int n;

    vector<vector<vector<bool>>> done;
    vector<vector<vector<bool>>> memo;

    bool enum_knapsack_2int(const vector<int>& nums, int i, int cnt, int sum){
        //pruning
        if(cnt > n/2) return false;
        if(sum > total_sum/2) return false;

        //no int overflow
        //can't use sum != 0, since nums[i] >= 0
        if(i==n) return sum * (n-cnt) == (total_sum-sum) * cnt && cnt != 0;

        if(done[i][cnt][sum] == true) return memo[i][cnt][sum];

        done[i][cnt][sum] = true;
        //choose or skip
        return memo[i][cnt][sum] = 
            enum_knapsack_2int(nums, i+1, cnt, sum) ||
            enum_knapsack_2int(nums, i+1, cnt+1, sum + nums[i]);
    }

    bool splitArraySameAverage(vector<int>& nums) {
        this->total_sum = 0;
        for(const int& x: nums) this->total_sum += x;

        this->n = nums.size();

        done.resize(n, vector<vector<bool>>(n/2+1, vector<bool>(total_sum/2+1, false) ) );
        memo.resize(n, vector<vector<bool>>(n/2+1, vector<bool>(total_sum/2+1) ) );

        return enum_knapsack_2int(nums, 0, 0, 0);
    }
};
