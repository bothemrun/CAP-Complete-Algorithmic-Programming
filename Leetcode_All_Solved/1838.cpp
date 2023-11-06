//m0

//Thinking Process

//[A] brute-force method for a fixed number:
//1. for a fixed number
//2. sort the whole array.
//3. increase each neighboring numbers forwards, and use all k.
//4. O(n^2)

//[B] can we speed up?
//1. we can get the the range sum of increase needed for a fixed number by variant prefix sum, called "prefix deficit".
//2. then we can binary search that variant prefix sum array.

//[C] Summary
//1. O(nlogn) by sort + binary searches.

#include<algorithm>
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
    int n;
    vector<long long> prefix;

    inline bool good(const vector<int>& nums, const long long& k, const long long& i, const long long& j){
        //[j, i] triangle
        if(j < 0) return false;


        long long big_rectangle = (long long)nums[i] * (i+1);
        long long left_rectangle = (long long)nums[i] * ((j-1) + 1);

        long long wedge = prefix[i] - ( (j-1>=0)? prefix[j-1]:0 );

        long long triangle = big_rectangle - left_rectangle - wedge;

        return triangle <= k;
    }

    int binary(const vector<int>& nums, const long long& k, const long long& i, const long long& low, const long long& high){

        long long mid = low + (high-low)/2LL;
        bool mid_good = good(nums, k, i, mid);
        if(mid_good && good(nums, k, i, mid-1)==false)
            return mid;
        assert(low != high);
        
        if(mid_good)
            return binary(nums, k, i, low, mid);
        else return binary(nums, k, i, mid+1, high);
    }

    int maxFrequency(vector<int>& nums, int k) {
        n = nums.size();

        sort(nums.begin(), nums.end());

        prefix.resize(n);
        prefix.front() = nums.front();
        for(int i=1;i<n;i++)
            prefix[i] = prefix[i-1] + (long long)nums[i];
        
        int max_freq = 0;
        for(int i=0;i<n;i++){
            //[j, i-1] applied with the increment operations.
            //so [j, i] good.
            int j = binary(nums, k, i, 0, i);

            max_freq = max(
                max_freq,
                i - (j-1)
            );
        }

        return max_freq;
    }
};
