//m1
//k size priority queue to keep the prefix/suffix k smallest.
//do the above for the prefix & the suffix.
//O(nlogn)

#include<queue>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int k;

    inline void keep_fixed_size_smallest(const vector<int>& nums, const int& begin, const int& end, const int& delta, vector<bool>& kbig){

        auto cmp_lam = [](const int& a, const int& b){
            return a < b;//max heap
        };

        priority_queue<int, vector<int>, decltype(cmp_lam)> size_maxheap(cmp_lam);

        kbig[begin] = false;
        for(int i=begin + delta; delta * i <= delta * end ;i += delta){

            size_maxheap.push( nums[ i - delta ] );
            if(size_maxheap.size() > k) size_maxheap.pop();

            kbig[i] = size_maxheap.size() == k && size_maxheap.top() < nums[i];
        }
    }

    int kBigIndices(vector<int>& nums, int k) {
        int n = nums.size();
        this->k = k;

        vector<bool> prefix_kbig(n, false);
        vector<bool> suffix_kbig(n, false);

        keep_fixed_size_smallest(nums, 0, n-1, 1, prefix_kbig);
        keep_fixed_size_smallest(nums, n-1, 0, (-1), suffix_kbig);

        int ans = 0;
        for(int i=0;i<n;i++)
            if(prefix_kbig[i] && suffix_kbig[i]) ans++;
        return ans;
    }
};
