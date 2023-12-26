//O(memo size) * O(time for each recursion)
//= O(n*target) * O(k)
//= O(30^2 * 1e3) = O(9e2 * 1e3) = O(9e5)

#define notyet (-1)
#define mod ((int)1e9 + 7)
#include<algorithm>
#include<assert.h>

class Solution {
public:
    int k;
    vector<vector<int>> memo;

    int enum_each_dice(const int& i, const int& target){
        if(target <= 0) return 0;

        if(i==0){
            return (target <= k)? 1:0;
        }

        if(memo[i][target] != notyet) return memo[i][target];

        int way = 0;
        for(int face=1;face <= min(k, target);face++){
            way = (
                way +
                enum_each_dice(i-1, target - face)
            )%mod;
        }

        return memo[i][target] = way;
    }

    int numRollsToTarget(int n, int k, int target) {
        this->k = k;

        memo.resize(n, vector<int>(target + 1, notyet));
        return enum_each_dice(n-1, target);
    }
};
