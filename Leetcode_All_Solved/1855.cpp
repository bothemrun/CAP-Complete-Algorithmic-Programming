#include<algorithm>
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        int max_d = 0;
        int i = 0;
        for(int j=0;j<n2;j++){
            //now nums1[i] too large, so ++ to decrease
            while(i < n1 && i < j && !(nums1[i] <= nums2[j]) )i++;
            if(i != n1)max_d = max(max_d, j-i);//NOTE: exceed
        }
        return max_d;
    }
};
