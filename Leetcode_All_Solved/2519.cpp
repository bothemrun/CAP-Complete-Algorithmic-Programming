//m0
//inversion pair with merge sort. O(nlogn).
//315. Count of Smaller Numbers After Self.
//counts of smaller numbers before & after self.

#define PII pair<int,int>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

enum{
    BEFORE,
    AFTER
};

class Solution {
public:

    void inversion_pair_merge_sort(const int& low, const int& high, vector<PII>& nums, vector<int>& smaller, const int& before_after){

        //base case
        if(low==high) return;

        //divide
        int mid = low + (high-low)/2;
        inversion_pair_merge_sort(low, mid, nums, smaller, before_after);
        inversion_pair_merge_sort(mid+1, high, nums, smaller, before_after);

        //conquer
        //for each nums[i] as the max bound, count nums[j_start + 1, j] < max bound.
        int i_start = low;
        int i_end = mid;
        int j_start = mid+1 - 1;
        int j_end = high;
        if(before_after == BEFORE){
            i_start = mid+1;
            i_end = high;
            j_start = low - 1;// >= 0 ?
            j_end = mid;
        }
        
        int j = j_start;
        for(int i=i_start;i<=i_end;i++){

            //ok with j = low-1 < 0
            while(
                j+1 <= j_end &&
                nums[i].first > nums[j+1].first
            ) j++;

            //ok with j = j_start = mid
            //ok with j = low-1 < 0
            smaller[ nums[i].second ] += j - j_start;
        }


        //merge
        auto cmp_lam = [](const PII& a, const PII& b){
            return a.first < b.first;
        };
        inplace_merge(nums.begin() + low, nums.begin() + mid+1, nums.begin() + high+1, cmp_lam);
    }

    int kBigIndices(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> smaller_before(n, 0);
        vector<int> smaller_after(n, 0);

        vector<PII> nums2i(n);
        for(int i=0;i<n;i++) nums2i[i] = PII(nums[i], i);
        vector<PII> nums2i_cpy = nums2i;//deep copy
        
        inversion_pair_merge_sort(0, n-1, nums2i, smaller_after, AFTER);
        inversion_pair_merge_sort(0, n-1, nums2i_cpy, smaller_before, BEFORE);



        int ans = 0;
        for(int i=0;i<n;i++){
            if(smaller_before[i] >= k && smaller_after[i] >= k) ans++;
        }
        return ans;
    }
};
