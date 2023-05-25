//m2
//binary search the answer in O(nlogS), where S := sum of nums.

//NOTE: proof of greedy:
//'cuz nums >= 0, it's not worse for previous subarray sums to take more.

//NOTE: proof of non-existing sums:
//think about an optimal partition. its max subarray sum (which exists) enforces a clear bound.

#include<algorithm>
#include<assert.h>
class Solution {
public:
    int bad_low;
    int k;
    
    inline bool good(const vector<int>& nums, const int& max_sum){
        //NOTE: edge for mid-1
        if(max_sum == bad_low) return false;


        int cur_sum = 0;//no overflow
        int partition = 0;
        for(const int& num: nums){
            if(cur_sum + num > max_sum){
                cur_sum = num;
                partition++;
            }else cur_sum += num;
        }

        partition++; //NOTE: last part

        return partition <= k;
    }

    int binary(const vector<int>& nums, const int& low, const int& high){
        int mid = low + (high-low)/2;

        bool mid_good = good(nums, mid);
        if( !good(nums, mid-1) && mid_good )
            return mid;
        if(low == high) assert(false);

        if(mid_good) return binary(nums, low, mid);
        else return binary(nums, mid+1, high);
    }

    int splitArray(vector<int>& nums, int k) {
        int max_all = *max_element(nums.begin(), nums.end());
        this->bad_low = max_all - 1;

        int sum_all = 0;//no overflow
        for(const int& num: nums) sum_all += num;
        
        this->k = k;
        return binary(nums, max_all, sum_all);
    }
};
