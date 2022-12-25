//NOTE: if x < y, a < b, 
//then xa + yb >= ya + xb, since 0 >= y(a-b) + x(b-a) == (y-x)(a-b) == + * -
//so any adjacent "inorder" can be swapped.
#include<algorithm>
bool cmp_fn(const int& a, const int& b){
    return a > b;//descending
}
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end(), cmp_fn);
        int sum = 0;
        for(int i=0;i<nums1.size();i++)
            sum += nums1[i] * nums2[i];
        return sum;
    }
};
