//O(n)
#define combi(m) (m*(m-1)/2)

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
    long long countGood(vector<int>& nums, int k) {
        long long n = nums.size();

        long long ans = 0;
        unordered_map<int, long long> cnt;
        long long win_pair = 0;

        //among satisfying subarrays with left ends at i,
        //[i, j] is the smallest.
        long long j = 0;
        cnt[ nums[0] ] = 1;

        for(long long i=0;i<n;i++){
            while(win_pair<k && j+1<n){
                j++;

                long long old_j = cnt[nums[j]];
                long long new_j = ++cnt[nums[j]];
                if(old_j >= 2) win_pair -= combi(old_j);
                if(new_j >= 2) win_pair += combi(new_j);
            }

            //ok for j+1==n
            if(win_pair >= k) ans += (n-1) - (j-1);

            //update, drop
            long long old_i = cnt[nums[i]];
            long long new_i = --cnt[nums[i]];
            assert(new_i >= 0);
            if(old_i >= 2) win_pair -= combi(old_i);
            if(new_i >= 2) win_pair += combi(new_i);
        }

        return ans;
    }
};
