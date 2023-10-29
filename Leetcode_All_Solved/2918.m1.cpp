//m1
//adding 0 count to sum.
//the logic is much better than dealing with all the edge cases of counts & sums.
//O(n)

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum_a = 0, sum_b = 0;
        long long cnt_a = 0, cnt_b = 0;
        for(const int& x: nums1){
            sum_a += x;
            if(x == 0) cnt_a++;
        }
        for(const int& x: nums2){
            sum_b += x;
            if(x == 0) cnt_b++;
        }

        //NOTE: crucial trick, 'cuz added numbers must >= 1
        sum_a += (long long)cnt_a;
        sum_b += (long long)cnt_b;


        if(sum_a < sum_b) return (cnt_a==0)? (-1):sum_b;
        if(sum_a > sum_b) return (cnt_b==0)? (-1):sum_a;
        return sum_a;
    }
};
