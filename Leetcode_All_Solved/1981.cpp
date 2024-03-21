//m0
//brute force pruning:

//[A] first actually brute force:
//1. a hash set of all possible sums in m*n
//2. each row enumerates all possible sums & the whole row.
//3. O(set size * m * n) = O(m^2 * n^2) = 2.4e7


//[B] pruning
//1. since target 800 < max sum 70^2
//2. use min sum (instead of max sum) to bound many large sums.
//3. by: sum - target < target - min sum (if min sum < target)

//4. so [A].3. becomes O(set size * m * n) = O(target * mn) = O(7.8e6)

#include<algorithm>
#include<stdlib.h>
#include<unordered_set>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat.back().size();

        int min_sum = 0;
        for(const vector<int>& row: mat)
            min_sum += *min_element(row.begin(), row.end());
        
        //edge case / first pruning
        if(!(target > min_sum)) return min_sum - target;

        //now min_sum < target
        //diff := target - min_sum
        //so bounded up to target + diff
        int max_bound = target + (target - min_sum);

        unordered_set<int> all_sums;
        all_sums.insert(0);

        for(const vector<int>& row: mat){
            unordered_set<int> all_sums2;

            for(const int& pre_sum: all_sums)
                for(const int& ele: row)if(pre_sum + ele < max_bound)
                    all_sums2.insert(pre_sum + ele);
            
            all_sums = all_sums2;
        }

        
        int min_diff = target - min_sum;
        for(const int& sum: all_sums)
            min_diff = min(min_diff, abs(sum - target) );
        
        return min_diff;
    }
};
