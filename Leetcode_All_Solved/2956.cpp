#define max_nums (100+1)
class Solution {
public:
    inline int help(const vector<int>& a, const vector<int>& b){
        bool has[max_nums] = {0};
        for(const int& x: b) has[x] = true;

        int ans = 0;
        for(const int& x: a) ans += has[x];
        return ans;
    }

    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        return vector<int>({
            help(nums1, nums2),
            help(nums2, nums1)
        });
    }
};
