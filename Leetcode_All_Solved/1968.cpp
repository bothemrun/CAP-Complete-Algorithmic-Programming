//m0
//construction by 280 Wiggle Sort
//construction by a permutation of [0, n-1]
//in-place O(1) space
#include<algorithm>
#include<queue>
#include<assert.h>
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        //NOTE: in-place
        queue<int> q;
        if(n <= 2)return nums;
        q.push(nums.front());
        q.push(nums.back());
        int low = 1, high = n-1 - 1;
        assert(low<n && high>=0);
        
        for(int i=0;i<n;i++){
            assert(q.size() != 0);
            nums[i] = q.front();
            q.pop();

            if(low <= high)
                q.push(nums[low++]);
            if(low <= high)
                q.push(nums[high--]);
        }

        return nums;
    }
};
