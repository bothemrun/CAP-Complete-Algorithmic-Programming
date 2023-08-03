//m0

//traps:
//(1) the "conquer" part must cross.
//(1.1) we go thru low~mid for crossing, and subtract the non-crossing part.
//(2) the prefix array is re-ordered after sorting.
//(3) to include the whole left part, we introduce "prefix_base".
//(3.1) but prefix_base is necessarily the least in the sorted prefix of the left part.
//(3.2) so we reset the sliding window.
//(4) we can't use call by reference since for prefix_base variable after sorting.



//first prefix sum.
//then divide & conquer, merge sort.
//, where divide & conquer merge sort is done on the prefix sum array.
//slightly similar applications to inversion pair.

//O(nlogn) overall.

//combined concepts in 
//(1) prefix sum. 
//(2) sliding window / two pointer. 
//(3) divide & conquer, merge sort

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
    long long lower, upper;
    vector<long long> prefix;

    inline int right_window(int& j_lower, const long long& prefix_minus, const long long& high){
        //window [j_lower, j_upper]
        while(
            j_lower <= high &&
            !(lower <= prefix[j_lower] - prefix_minus)
        ) j_lower++;

        //NOTE: must check <= upper
        if(
            !(j_lower <= high) ||
            !(prefix[j_lower] - prefix_minus <= upper)
        ) return 0;

        int j_upper = j_lower;
        while(
            j_upper+1<=high &&
            prefix[j_upper+1] - prefix_minus <= upper
        ) j_upper++;

        return j_upper - (j_lower-1);
    }

    void merge_sort_prefix_base(const int& low, const int& high, const long long prefix_base){
        //NOTE: prefix_base can't call by reference, since prefix array is re-ordered.

        //base case
        if(low == high){
            long long sum = prefix[high] - prefix_base;
            ans += (lower <= sum && sum <= upper);
            return;
        }

        
        //divide
        int mid = low + (high-low)/2;
        const long long prefix_mid_before_sort = prefix[mid];

        merge_sort_prefix_base(low, mid, prefix_base);
        merge_sort_prefix_base(mid+1, high, prefix_mid_before_sort);

        //conquer
        //NOTE: prefix_base isn't necessarily the front of sorted prefix left half
        int j_lower = mid + 1;
        ans += right_window(j_lower, prefix_base, high);

        //NOTE: must reset
        j_lower = mid + 1;
        for(int i=low;i <= mid;i++)
            ans += right_window(j_lower, prefix[i], high);
        
        //NOTE: for conquer, must "cross"
        //NOTE: and prefix array is re-ordered
        j_lower = mid + 1;//reset
        ans -= right_window(j_lower, prefix_mid_before_sort, high);


        //merge
        inplace_merge(prefix.begin() + low, prefix.begin() + mid+1, prefix.begin() + high+1);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        this->lower = lower;
        this->upper = upper;

        prefix.resize(n);
        for(int i=0;i<n;i++)
            prefix[i] = (long long)nums[i] + ((i-1>=0)? prefix[i-1]:0);
        
        
        merge_sort_prefix_base(0, n-1, 0);
        return ans;
    }
};
