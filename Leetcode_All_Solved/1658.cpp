//m0
//O(nlogn) for n binary searches

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
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        vector<long long> prefix(n);
        prefix.front() = nums.front();
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1] + nums[i];
        
        const int impossible = n+1;
        int min_op = impossible;

        for(int i=0;i<n;i++){
            if(prefix[i] == x)
                min_op = min(min_op, i+1);
            
            long long suffix = prefix.back() - prefix[i];
            if(i != n-1 && suffix == x)
                min_op = min(min_op, (n-1) - i);
        }

        long long suffix = 0;
        for(int i=n-1;i>=1;i--){
            suffix += nums[i];

            int idx = lower_bound(prefix.begin(), prefix.end(), x - suffix) - prefix.begin();

            if(idx >= i) continue;
            if(prefix[idx] != x - suffix) continue;

            min_op = min(min_op, (idx + 1) + (n - i) );
        }

        if(min_op == impossible) return (-1);
        return min_op;
    }
};
