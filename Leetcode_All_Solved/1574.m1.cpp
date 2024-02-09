//m1
//2972. Count the Number of Incremovable Subarrays II hard
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
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        //[0, left] & [right, n-1] non-decreasing
        int left=0;
        while(left+1<n && arr[left] <= arr[left+1]){
            left++;
        }

        int right=n-1;
        while(right-1>=0 && arr[right-1] <= arr[right]){
            right--;
        }


        //1. result is empty
        int ans = n;

        //2. result only from left
        ans = min(ans, (n-1) - left);

        //3. result only from right
        ans = min(ans, (right-1) - (0-1));

        //4. result from both ends
        //[0, i] concat [j, n-1]
        //since we must remove something,
        //i+2 <= j
        int j = right;
        for(int i=0;i<=min(left, n-3);i++){

            //NOTE: must i+2 <= j
            j = max(j, i+2);
            
            while(j<n && !( arr[i] <= arr[j] ) ){
                j++;
            }

            if(j==n) break;
            ans = min(ans, (j-1) - i);
        }

        return ans;
    }
};
