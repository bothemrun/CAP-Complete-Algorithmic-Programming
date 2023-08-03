//m0
//inversion pair with merge sort. O(nlogn)

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
    int ans = 0;
    void inversion_pair_merge_sort(vector<int>& nums, const int& low, const int& high){
        //base case
        if(low==high) return;

        //divide
        int mid = low + (high-low)/2;
        inversion_pair_merge_sort(nums, low, mid);
        inversion_pair_merge_sort(nums, mid+1, high);

        //conquer
        int j = mid; //[mid+1, j] good
        for(int i=low;i<=mid;i++){
            while(j+1<=high && (long long)nums[i] > 2 * (long long)nums[j+1] ){
                j++;
            }

            ans += j - (mid+1 - 1);
        }

        //merge
        inplace_merge(nums.begin() + low, nums.begin() + mid+1, nums.begin() + high+1);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        inversion_pair_merge_sort(nums, 0, n-1);
        return ans;
    }
};
