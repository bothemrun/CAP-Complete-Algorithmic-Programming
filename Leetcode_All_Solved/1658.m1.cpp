//m1
//O(n) by prefix hash

#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        const int impossible = n+1;
        int min_op = impossible;

        long long prefix_sum = 0;
        for(int i=0;i<n;i++){
            prefix_sum += nums[i];
            if(prefix_sum == x){
                min_op = i+1;
                break;
            }
        }
        
        long long suffix_sum = 0;
        for(int i=n-1;i>=0;i--){
            suffix_sum += nums[i];
            if(suffix_sum == x){
                min_op = min(min_op, (n-1) - (i-1));
                break;
            }
        }


        unordered_map<long long, int> prefix2i;
        vector<long long> prefix(n);
        prefix.front() = nums.front();

        for(int i=0;i<n;i++){
            if(i != 0) prefix[i] = prefix[i-1] + nums[i];

            //choose the min index
            if(prefix2i.count(prefix[i]) == 0)
                prefix2i[prefix[i]] = i;
        }

        long long suffix = 0;
        for(int i=n-1;i>=1;i--){
            suffix += nums[i];

            //update
            //since we store the smallest index, so just remove it.
            //don't worry about a list of indices
            prefix2i.erase( prefix[i] );


            if(prefix2i.count( x - suffix ) != 0)
                min_op = min(min_op, (n-1) - (i-1)  +  prefix2i[ x - suffix ] + 1 );
        }

        if(min_op == impossible) return (-1);
        return min_op;
    }
};
