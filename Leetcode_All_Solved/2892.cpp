//m0
//recursion with memo + edge case for 0 + pruning by 1
//so O(n log_2(k) ) due to pruning by 1
//pruning by 1 from O(n^2) to O(n log_2(n))

#define notyet (-1)
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
    vector<int> pruned;
    vector<int> memo;
    int enum_partition(const int& i, const int& k){
        if(i<0) return 0;

        if(memo[i] != notyet) return memo[i];

        //[j, i] into 1 partition
        int min_len = 1 + enum_partition(i-1, k);
        long long product = pruned[i];
        for(int j=i-1;j>=0;j--){
            product *= pruned[j];
            if(product > k) break;

            min_len = min(
                min_len,
                1 + enum_partition(j-1, k)
            );
        }

        return memo[i] = min_len;
    }

    int minArrayLength(vector<int>& nums, int k) {
        //NOTE: pruning by 1 from O(n^2) to O(n log_2(n))
        int nums_size = nums.size();
        int i=0;
        while(i<nums_size){
            const int& x = nums[i];
            if(x==0) return 1;
            if(x==1){
                //NOTE: edge case: [1, 5] k=4
                pruned.push_back(1);
                while(i<nums_size && nums[i]==1) i++;
            }else{
                pruned.push_back(x);
                i++;
            }
        }


        int n = pruned.size();
        memo.resize(n, notyet);
        return enum_partition(n-1, k);
    }
};
