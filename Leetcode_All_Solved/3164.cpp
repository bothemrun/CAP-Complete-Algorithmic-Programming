//O(nlogV), V := max nums
#define max_nums ((int)1e6 + 1)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int cnt1fac[max_nums] = {0};

        for(int x: nums1)if(x%k == 0){
            x /= k;

            for(int f=1;f*f<=x;f++)if(x%f == 0){
                cnt1fac[f]++;

                //trap
                if(f != x/f) cnt1fac[x/f]++;
            }
        }

        long long ans = 0;
        for(const int& y: nums2){
            ans += cnt1fac[y];
        }
        return ans;
    }
};
