#define offset 1000
#define max_num 2001
class Solution {
public:
    inline void diff_set(const vector<int>& nums1, const vector<int>& nums2, vector<int>& ans1){
        bool iset[max_num] = {0};
        for(const int& num: nums1) iset[num+offset] = true;
        for(const int& num: nums2) iset[num+offset] = false;
        for(int i=0;i<max_num;i++)if(iset[i]) ans1.push_back(i - offset);
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        diff_set(nums1, nums2, ans[0]);
        diff_set(nums2, nums1, ans[1]);
        return ans;
    }
};
