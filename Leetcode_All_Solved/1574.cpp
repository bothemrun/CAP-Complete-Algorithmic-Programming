//m0
//2972. Count the Number of Incremovable Subarrays II hard
//O(nlogn)

#include<assert.h>
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        //[0, left] & [right, n-1] strictly increasing
        int left = 0;
        while(left+1<n && arr[left] <= arr[left+1]){
            left++;
        }

        int right = n-1;
        while(right-1>=0 && arr[right-1] <= arr[right]){
            right--;
        }


        //1. result is empty
        int ans = n-1;

        //2. result is the original array
        if(left==n-1){
            assert(right==0);
            return 0;
        }

        //3. result only from prefix
        ans = min(ans, (n-1) - left);

        //4. result only from suffix
        ans = min(ans, (right-1) - (0-1));

        //5. result from both ends.
        //must remove something in the middle
        for(int i=0;i<=min(left, n-3);i++){
            //[0, i] concat [j, n-1]
            //i+2 <= j, since we must remove something
            int j = lower_bound(
                arr.begin() + max(right, i+2),
                arr.end(),
                arr[i]
            ) - arr.begin();

            if(j<n) ans = min(ans, (j-1) - i);
        }

        return ans;
    }
};
