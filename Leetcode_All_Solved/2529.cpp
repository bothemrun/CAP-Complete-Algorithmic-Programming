#include<algorithm>
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int nonneg_low = 0;
        while(nonneg_low < n && nums[nonneg_low] < 0){
            nonneg_low++;
        }
        int pos_low = nonneg_low;
        while(pos_low < n && nums[pos_low] <= 0){
            pos_low++;
        }
        int neg = (nonneg_low - 1) - (0-1);
        int pos = (n-1) - (pos_low-1);
        
        //cout << pos << " "<< neg<<endl; 
        return max(neg, pos);
    }
};
