//O(nlogn)
#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();

        //[0, left] & [right, n-1] strictly increasing
        int left = 0;
        while(left+1<n && nums[left] < nums[left+1]){
            left++;
        }

        int right = n-1;
        while(right-1>=0 && nums[right-1] < nums[right]){
            right--;
        }


        long long ans = 0;

        //1. result is empty
        ans += 1;

        //NOTE: from now on, result shall be nonempty, 
        //NOTE: and shouldn't be the original array, since we must remove something.

        //2. result only from [0, left]
        ans += min(left, n-2) - (0-1);

        //3. result only from [right, n-1]
        ans += (n-1) - ( max(right, 1) - 1 );

        //4. result from both parts.
        //the result still nonempty
        //but we must remove something
        for(int i=0;i<=min(n-3, left);i++){
            //left part [0, i] + right part [j, n-1]
            int j = upper_bound(
                nums.begin() + max(right, i+2),
                nums.end(),
                nums[i]
            ) - nums.begin();

            if(j<n) ans += (n-1) - (j-1);
        }

        return ans;
    }
};
