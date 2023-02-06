#include<assert.h>
#include<queue>
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int yi = n;

        queue<int> qx;
        if(n == 1)return nums;
        assert(nums.size() >= 2*2);
        qx.push(nums.front());
        qx.push(nums[1]);

        for(int xi=0;xi<2*n;xi+=2){
            assert(qx.size() != 0);
            nums[xi] = qx.front();
            qx.pop();

            nums[xi+1] = nums[yi];

            //NOTE: update 2 x
            if(xi+2 < 2*n)
                qx.push(nums[xi+2]);
            if(xi+3 < 2*n)
                qx.push(nums[xi+3]);
            
            //NOTE: won't catch up with yi
            yi++;
        }

        return nums;
    }
};
