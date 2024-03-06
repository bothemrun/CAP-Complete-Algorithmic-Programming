//O(nlog(max_nums))
#define max_nums ((int)1e6)
#define ceil(a, b) ( (a%b==0)? a/b:(a/b+1) )

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
    int threshold;

    inline bool good(const vector<int>& nums, const int& divisor){
        //test cases quaranteed to have an answer
        if(divisor==0) return false;
        assert(divisor >= 1);

        long long sum = 0;
        for(const int& x: nums)
            sum += ceil(x, divisor);
        return sum <= threshold;
    }

    int binary(const vector<int>& nums, const int& low, const int& high){
        int mid = low + (high-low)/2;
        int mid_res = good(nums, mid);
        if(good(nums, mid-1)==false && mid_res) return mid;

        //test cases quaranteed to have an answer
        assert(low != high);

        if(mid_res==true) return binary(nums, low, mid);
        else return binary(nums, mid+1, high);
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        n = nums.size();
        this->threshold = threshold;

        return binary(nums, 1, max_nums);
    }
};
