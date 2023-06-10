#define SUM1(low, high) ( ( (low+high)*( high - (low-1) ) )/2 )
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
    long long n, index, maxSum;
    inline bool good(const long long& nums_index){
        long long sum = nums_index;

        long long left_len = (index-1) - (0-1);
        if(left_len > 0){
            long long leftmost = nums_index - left_len;
            if(leftmost > 0){
                //NOTE: all slope down
                assert(leftmost <= nums_index-1);
                sum += SUM1(leftmost, nums_index-1);
            }else{
                //NOTE: slope down
                if(1 <= nums_index-1)
                    sum += SUM1(1, nums_index-1);
            
                //NOTE: all flat 1
                long long start0 = index - nums_index;
                assert(start0 >= 0);
                sum += (start0 - (0-1));
            }
        }

        long long right_len = (n-1) - (index+1 - 1);
        if(right_len > 0){
            long long rightmost = nums_index - right_len;
            if(rightmost > 0){
                //NOTE: all slope down
                assert(rightmost <= nums_index-1);
                sum += SUM1(rightmost, nums_index-1);
            }else{
                //NOTE: slope down
                if(1 <= nums_index-1)
                    sum += SUM1(1, nums_index-1);
            
                //NOTE: all flat 1
                long long start0 = index + nums_index;
                assert(start0 < n);
                sum += (n-1) - (start0 - 1);
            }
        }

        return sum <= maxSum;
    }
    int binary(const int& low, const int& high){
        long long mid = low + (high-low)/2;
        bool mid_tmp = good(mid);
        if(mid_tmp && !good(mid+1)) return mid;
        //can't have no results, since n <= maxSum,
        //so there exists 1 answer where all nums[i] == 1
        assert(low != high);

        if(mid_tmp) return binary(mid+1, high);
        else return binary(low, mid);
    }
    int maxValue(int n, int index, int maxSum) {
        this->n = n;
        this->index = index;
        this->maxSum = maxSum;
        return binary(1, maxSum);
    }
};
