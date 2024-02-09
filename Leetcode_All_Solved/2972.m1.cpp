//m1
//O(n)

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
        int left=0;
        while(left+1<n && nums[left] < nums[left+1]){
            left++;
        }

        int right=n-1;
        while(right-1>=0 && nums[right-1] < nums[right]){
            right--;
        }


        //1. result is empty
        long long ans = 1;

        //note that we must remove someting
        //2. result only from left
        ans += min(left, n-2) - (0-1);

        //3. result only from right
        ans += (n-1) - ( max(right, 1) - 1 );

        //4. result from both ends
        //since we must remove something,
        //i+2 <= j
        int j = right;
        for(int i=0;i<=min(left, n-3);i++){
            //we must remove something
            j = max(j, i+2);

            while(j<n && !( nums[i] < nums[j] ) ){
                j++;
            }

            if(j==n) break;
            ans += (n-1) - (j-1);
        }

        return ans;
    }
};
