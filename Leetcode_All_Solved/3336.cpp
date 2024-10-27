//originally, brute force enumerating subsets --> O(2^n).

//if we observe the "states" of current gcd:
//we can have max possible gcd bound it. hence dp also bounded.
//O(n * max gcd * max gcd) = O(200^3) = 8e6

#define max_gcd 200
#include<numeric> //C++17 gcd() lcm()

class Solution {
public:
    const int mod = (int)1e9 + 7;
    int n;
    const int notyet = (-1);
    vector<vector<vector<int>>> memo;

    int enum_subsets(const vector<int>& nums, int i, int gcd1, int gcd2){
        if(i==n){
            if(gcd1 == 0 || gcd2 == 0) return 0;//empty subsequence
            return gcd1 == gcd2;
        }

        if(memo[i][gcd1][gcd2] != notyet) return memo[i][gcd1][gcd2];

        //choose or not
        int ret = enum_subsets(nums, i+1, gcd1, gcd2);
        ret = (
            ret + enum_subsets(nums, i+1, gcd(gcd1, nums[i]), gcd2 )
        )%mod;
        ret = (
            ret + enum_subsets(nums, i+1, gcd1, gcd(gcd2, nums[i]) )
        )%mod;
        return memo[i][gcd1][gcd2] = ret;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->n = nums.size();
        memo.resize(n, vector<vector<int>>(max_gcd+1, vector<int>(max_gcd+1, notyet) ) );
        return enum_subsets(nums, 0, 0, 0);
    }
};
