//m0
//recursion with memo. with pruning. O(n)

#define max_n ((int)1e5 + 1)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    //fast init to 0 by array
    bool done[max_n] = {0};
    bool memo[max_n] = {0};

    bool enum_partition(const vector<int>& nums, const int& i){
        if(i == (-1)) return true;
        if(i<=0) return false;

        //pruning
        if(i==1){
            return nums[i] == nums[i-1];
        }
        if(i==2){
            return ( nums[i] == nums[i-1] && nums[i] == nums[i-2] ) ||
            ( nums[i] - 1 == nums[i-1] && nums[i] - 2 == nums[i-2] );
        }

        if(done[i] == true) return memo[i];

        //NOTE: enum this partition
        bool ret = false;
        if(nums[i] == nums[i-1])
            ret |= enum_partition(nums, i-2);

        //pruning
        if(!(i-2 >= 0)){
            done[i] = true;
            return memo[i] = ret;
        }

        //3 elements
        if(!ret && nums[i] == nums[i-1] && nums[i] == nums[i-2] )
            ret |= enum_partition(nums, i-3);
        
        if(!ret && nums[i] - 1 == nums[i-1] && nums[i] - 2 == nums[i-2] )
            ret |= enum_partition(nums, i-3);
        
        done[i] = true;
        return memo[i] = ret;
    }

    bool validPartition(vector<int>& nums) {
        n = nums.size();

        return enum_partition(nums, n-1);
    }
};
