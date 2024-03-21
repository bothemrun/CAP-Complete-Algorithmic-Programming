//m2

//knapsack dp + pruning

//1. since it's abs, recursion can only start from f(0), not things like f(target)

//2. as in m0, target << max sum, so have a max bound by min sum.

//3. improved from O(m * max sum * n) to O(m * target * n)

//4. further pruning: 
//a. if returned difference == 0 or
//b. sort all rows, if current prefix sum already crosssed target once, then break.

#include<algorithm>
#include<stdlib.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
private:
    int m, n;
    
    vector<vector<int>> memo;
    const int notyet = INT_MAX;
    const int impossible = INT_MAX-1;

    int max_bound;

    int knapsack_enum_tree(const vector<vector<int>>& mat, int i, int sum, const int target){
        if(i==m) return abs(sum - target);

        //pruning
        if(sum > max_bound) return impossible;

        if(memo[i][sum] != notyet) return memo[i][sum];

        int ret = impossible;
        for(const int& x: mat[i]){
            ret = min(
                ret,
                knapsack_enum_tree(mat, i+1, sum+x, target)
            );

            //further pruning
            if(ret == 0 || sum+x >= target) break;
        }
        
        return memo[i][sum] = ret;
    }

public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m = mat.size();
        n = mat.back().size();

        int min_sum = 0;
        for(vector<int>& row: mat){
            sort(row.begin(), row.end());
            min_sum += row.front();
        }
        
        //first pruning
        if(!(min_sum < target)) return min_sum - target;

        //now min_sum < target, upper bound
        max_bound = target + (target - min_sum);

        memo.resize(m, vector<int>(max_bound + 1, notyet));
        return knapsack_enum_tree(mat, 0, 0, target);
    }
};
