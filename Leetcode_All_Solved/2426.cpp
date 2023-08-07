//m0
//inversion pair with merget sort. O(nlogn)
//sorted on nums := nums1 - nums2
//nums[i] <= nums[j] + diff

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
    long long ans = 0;
    int diff;
    vector<int> nums;

    void inversion_pair_merge_sort(const int& low, const int& high){
        //base case
        if(low==high) return;

        //divide
        int mid = low + (high-low)/2;
        inversion_pair_merge_sort(low, mid);
        inversion_pair_merge_sort(mid+1, high);

        //conquer
        int j = mid + 1;
        for(int i=low;i<=mid;i++){
            while( j<=high && !( nums[i] <= nums[j] + diff ) ) j++;

            //ok for j == high+1
            ans += high - (j-1);
        }

        //merge
        inplace_merge(nums.begin() + low, nums.begin() + mid+1, nums.begin() + high+1);
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        this->diff = diff;

        nums.resize(n);
        for(int i=0;i<n;i++) nums[i] = nums1[i] - nums2[i];

        inversion_pair_merge_sort(0, n-1);
        return ans;
    }
};
