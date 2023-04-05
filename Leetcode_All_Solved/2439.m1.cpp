//m1
//O( n log(1e9) ) binary search the possible answers
//2 versions to check bounds: backward(loan) & forward(saving), here's the forward saving.
#define max_num ((int)(1e9))
#include<assert.h>
#include<algorithm>
class Solution {
public:
    int n;
    inline bool enough(const vector<int>& nums, const int& bound){
        //forward saving. can't use saving of the future if there's no saving.
        long long saving = 0;
        for(int i=0;i<n;i++){
            if(nums[i] <= bound) saving += bound - nums[i];
            else{
                //forward saving. can't use saving of the future if there's no saving.
                if(saving >= nums[i] - bound)
                    saving -= nums[i] - bound;
                else return false;//NOTE: no saving now, life fucked up.
            }
        }
        return true;
    }

    int binary(const vector<int>& nums, const int& low, const int& high){
        int mid = low + (high-low)/2;
        bool mid_tmp = enough(nums, mid);
        if(enough(nums, mid-1) == false && mid_tmp == true) return mid;
        if(low == high) assert(false);

        if(mid_tmp)
            return binary(nums, low, mid);
        else return binary(nums, mid+1, high);
    }
    int minimizeArrayValue(vector<int>& nums) {
        n = nums.size();
        return binary(nums, 0, max_num);
    }
};
