//m0
//O( n log(1e9) ) binary search the possible answers
//2 versions to check bounds: backward(loan) & forward(saving), here's the backward loan.
#define max_num ((int)1e9)
#include<assert.h>
#include<algorithm>
class Solution {
public:
    int n;
    inline bool enough(const vector<int>& nums, const int& bound){
        //backward loan. can't pay the debt of the future if there's no debt now.
        long long loan = 0;
        for(int i=n-1;i>=0;i--){
            if(nums[i] >= bound) loan += nums[i] - bound;
            else{
                //backward loan. can't pay the debt of the future if there's no debt now.
                if(loan > 0)
                    loan = max(0LL, loan - (bound - nums[i]) );
            }
        }
        return loan == 0;
    }

    int binary(const vector<int>& nums, const int& low, const int& high){
        int mid = low + (high-low)/2;
        if(enough(nums, mid-1) == false && enough(nums, mid) == true)
            return mid;
        if(low == high) assert(false);

        if(enough(nums, mid))
            return binary(nums, low, mid);
        else return binary(nums, mid+1, high);
    }
    int minimizeArrayValue(vector<int>& nums) {
        n = nums.size();
        return binary(nums, 0, max_num);
    }
};
