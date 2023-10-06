//O(n)
//for a fixed middle interval [j, j+(k-1)],
//we can use prefix max & suffix max for the front & back interval respectively.

#define P2I pair<int,int>
#define PIV pair<int, vector<int> >
#include<utility>
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
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        //no overflow
        vector<int> sum(n-(k-1));
        sum.front() = 0;
        for(int i=0;i<k;i++)
            sum.front() += nums[i];
        
        for(int i=1;i+(k-1)<n;i++)
            sum[i] = sum[i-1] - nums[i-1] + nums[i+(k-1)];
        


        auto cmp = [](const P2I& a, const P2I& b){
            if(a.first != b.first) return a.first < b.first; //sum
            return a.second > b.second; //lexicographically smaller index
        };

        vector<P2I> prefix_max(n);
        prefix_max[0] = P2I(sum[0], 0);
        for(int i=1;i+(k-1)<n;i++)
            prefix_max[i] = max(
                prefix_max[i-1],
                P2I( sum[i], i ),
                cmp
            );
        
        
        vector<P2I> suffix_max(n);
        suffix_max[n-k] = P2I(sum[n-k], n-k);
        for(int i=n-k-1;i>=0+k;i--)
            suffix_max[i] = max(
                suffix_max[i+1],
                P2I( sum[i], i ),
                cmp
            );

        

        PIV max3 = PIV( (-1), vector<int>({n, n, n}) );
        auto cmp2 = [](const PIV& a, const PIV& b){
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        };
        for(int j=k;j+k<n;j++){
            max3 = max(
                max3,
                PIV( sum[j] + prefix_max[j-k].first + suffix_max[j+k].first, vector<int>({
                    prefix_max[j-k].second, j, suffix_max[j+k].second
                }) ),
                cmp2
            );
        }

        return max3.second;
    }
};
