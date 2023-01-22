#include<stdlib.h>
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0){
            for(int i=0;i<nums1.size();i++)if(nums1[i] != nums2[i])
                return (-1);
            return 0;
        }
        
        long long dk = 0;
        long long cnt_pos = 0;
        for(int i=0;i<nums1.size();i++){
            long long d = (long long)nums1[i] - (long long)nums2[i];
            //if(abs(d) %k != 0)return (-1);
            if(d >= 0){
                if(d%k != 0)return (-1);
            }else{
                if((-d) %k != 0)return (-1);
            }
            
            dk += d/k;
            if(d > 0) cnt_pos += d/k;
        }
        if(dk != 0)return (-1);
        return cnt_pos;
    }
};
