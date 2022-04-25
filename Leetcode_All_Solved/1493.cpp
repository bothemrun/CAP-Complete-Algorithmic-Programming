#include<algorithm>
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_ans = 0;
        int region_len = 0;
        int pre_region_len = 0;
        bool concatable = false;
        bool in_region = false;
        nums.push_back(0);//dummy for the end
        bool all_one = true;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(x == 1 && in_region == false){
                in_region = true;
                if(i >= 2 && nums[i-2] == 1)concatable = true;
                else concatable = false;
                
                region_len = 1;
            }else if(x == 0 && in_region == true){
                in_region = false;
                
                max_ans = max(max_ans, region_len);
                if(concatable == true)max_ans = max(max_ans, region_len + pre_region_len);
                
                //update
                pre_region_len = region_len;
            }else if(x == 1 && in_region == true){
                region_len++;
            }
            
            if(x == 0 && i != nums.size()-1)all_one = false;
        }
        //cout << all_one;
        //must delete one element
        return (all_one == true)? (nums.size()-1-1):max_ans;
    }
};
