//m0
//sorting, then build by construction: what to do with a permutation of [0, n-1]?'
//in-place
#include<assert.h>
#include<algorithm>
#include<queue>
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        //NOTE: in-place
        queue<int> q;
        if(n <= 2)return;
        q.push(nums.front());
        q.push(nums.back());
        int low = 1, high = n-1 - 1;
        assert(low < n && high>=0);
        for(int i=0;i<n;i++){
            assert(q.size() != 0);
            nums[i] = q.front();
            q.pop();

            if(low <= high)
                q.push(nums[low++]);
            if(low <= high)
                q.push(nums[high--]);
        }

        return;
    }
};
