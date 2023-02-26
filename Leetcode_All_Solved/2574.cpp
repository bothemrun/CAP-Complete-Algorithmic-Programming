#include<assert.h>
#include<stdlib.h>
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        assert(n >= 1);
        left.front() = 0;
        vector<int> right(n);
        right.back() = 0;
        
        for(int i=1;i<n;i++){
            left[i] = left[i-1] + nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1] + nums[i+1];
        }
        
        vector<int> ans (n);
        for(int i=0;i<n;i++){
            ans[i] = abs(left[i] - right[i]);
        }
        return ans;
    }
};
