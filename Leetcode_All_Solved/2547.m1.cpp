//m1

//wisdompeak's Interval I Partition dp
//O(n^2)

//use arrays / vectors instead of hash map.
//which may sometimes run faster practically.

//#define max_nums 1000

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<long long> memo;
    const long long notyet = (-1);
    long long k;

    long long enum_last_partition(const vector<int>& nums, const int& i){
        if(i<0) return 0;

        if(memo[i] != notyet) return memo[i];

        long long min_cost = LLONG_MAX;

        //unordered_map<int, int> cnt;
        //fast init to 0 by array
        //int cnt[max_nums+1] = {0};
        vector<int> cnt( (int)nums.size()+1, 0 );
        int importance = 0;

        //[j, i] forms a part
        for(int j=i;j>=0;j--){
            cnt[ nums[j] ]++;
            if(cnt[ nums[j] ] == 2) importance += 2;
            else if(cnt[ nums[j] ] >= 3) importance++;

            min_cost = min(
                min_cost,
                k + importance +
                enum_last_partition(nums, j-1)
            );
        }

        return memo[i] = min_cost;
    }

    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        this->k = k;
        
        memo.resize(n, notyet);
        return enum_last_partition(nums, n-1);
    }
};
