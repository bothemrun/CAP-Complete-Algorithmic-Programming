#include<limits.h>
#include<algorithm>
class Solution {
private:
    int max_product = INT_MIN;
    bool global_has_0 = false;
    
    inline void segment_after1st_neg(const vector<int>& nums){
        int segment_product = INT_MIN;
        int after1st_neg_product = INT_MIN;//NOTE: subarray product by division has problems: segment with only 1 element, and it's negative.
        bool met_1st_neg = false;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(x == 0){
                //clearance for 0
                max_product = max(max_product, segment_product);
                max_product = max(max_product, after1st_neg_product);
                
                //reset
                segment_product = INT_MIN;
                after1st_neg_product = INT_MIN;
                met_1st_neg = false;
                
                global_has_0 = true;
                continue;
            }
            
            //update segment
            segment_product = (segment_product == INT_MIN)? x:x*segment_product;
            if(met_1st_neg == true)
                after1st_neg_product = (after1st_neg_product == INT_MIN)? x:x*after1st_neg_product;
            if(met_1st_neg == false && x < 0){
                met_1st_neg = true;
                //not multiply 1st negative
            }
            
            //clearance for last element
            if(i == nums.size()-1){
                max_product = max(max_product, segment_product);
                max_product = max(max_product, after1st_neg_product);
            }
        }
    }
public:
    int maxProduct(vector<int>& nums) {
        segment_after1st_neg(nums);
        reverse(nums.begin(), nums.end());
        segment_after1st_neg(nums);
        
        return (max_product > 0)? max_product:( (global_has_0)? 0:max_product );
    }
};
