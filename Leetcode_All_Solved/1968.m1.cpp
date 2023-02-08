//m1
//construction by 280 Wiggle Sort
//O(n)
#include<algorithm>
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(i%2 == 0){
                //NOTE: since all distinct
                if(!(nums[i] < nums[i+1]))
                    swap(nums[i], nums[i+1]);
            }
            else{
                if(!(nums[i] > nums[i+1]))
                    swap(nums[i], nums[i+1]);
            }
        }

        return nums;
    }
};
