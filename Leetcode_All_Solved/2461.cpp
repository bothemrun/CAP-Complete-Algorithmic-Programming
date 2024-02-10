//O(n)
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
    unordered_map<int, int> cnt;
    long long sum = 0;
    int distinct = 0;

    inline void add(const int& x){
        sum += x;

        int c = ++cnt[x];
        if(c==1) distinct++;
        else if(c==2) distinct--;
    }

    inline void drop(const int& x){
        sum -= x;

        int c = --cnt[x];
        if(c==1) distinct++;
        else if(c==0) distinct--;

        assert(c >= 0);
    }

    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        //first window
        for(int i=0;i<k-1;i++)
            add(nums[i]);
        
        for(int r=k-1;r<n;r++){
            //update, add
            add(nums[r]);

            if(distinct == k) ans = max(ans, sum);

            //update, drop
            int l = r - (k-1);
            drop(nums[l]);
        }

        return ans;
    }
};
