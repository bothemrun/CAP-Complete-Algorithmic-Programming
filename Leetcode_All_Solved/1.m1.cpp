//m1
//prefix hash in O(n) but O(n) space
//two pointer squeeze matrix & triangle in O(nlogn) but O(1) space.

#include<unordered_map>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> prefix_hash;

        for(int i=0, n=nums.size();i<n;i++){
            if(prefix_hash.count(target - nums[i]) != 0)
                return vector<int>({
                    prefix_hash[target - nums[i] ],
                    i
                });
            
            //update prefix hash, don't care about duplicates
            prefix_hash[nums[i]] = i;
        }

        assert(false);
        return vector<int>({-1, -1});
    }
};
