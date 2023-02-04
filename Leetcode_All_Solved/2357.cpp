#include<algorithm>
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int op = 0;
        int zero = 0;
        int i = 0;
        while(i < n){
            while(i < n && zero == nums[i]){
                i++;
            }
            if(!(i < n))break;

            zero = nums[i];
            op++;
        }
        return op;
    }
};
