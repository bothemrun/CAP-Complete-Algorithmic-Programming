//m0
//inversion pair. divide & conquer, merge sort. O(nlogn)

#define PII pair<int,int>
#include<algorithm>
#include<utility>
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
    vector<int> ans;
    vector<PII> nums2i;

    void inversion_pair_merge_sort(const int& low, const int& high){
        //base case
        if(low==high) return;

        //divide
        int mid = low + (high-low)/2;
        inversion_pair_merge_sort(low, mid);
        inversion_pair_merge_sort(mid+1, high);

        //conquer
        //[mid+1, j]
        int j = mid+1 - 1;
        assert(j >= 0);
        for(int i=low;i<=mid;i++){
            while(j+1<=high && nums2i[i].first > nums2i[j+1].first ){
                j++;
            }

            ans[ nums2i[i].second ] += j - mid;
        }

        //merge
        auto cmp_lam = [](const PII& a, const PII& b){
            return a.first < b.first;
        };
        inplace_merge(nums2i.begin()+low, nums2i.begin() + mid+1, nums2i.begin() + high+1, cmp_lam);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        nums2i.resize(n);
        for(int i=0;i<n;i++)
            nums2i[i] = PII(nums[i], i);
        
        ans.resize(n, 0);
        inversion_pair_merge_sort(0, n-1);
        return ans;
    }
};
