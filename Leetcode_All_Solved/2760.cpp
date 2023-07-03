//NOTE: don't care about nums[l]%2 == 0
//NOTE: just check (1) <= threshold. (2) alternating parity.

//NOTE: make a bool vector for the good "non-head" window elements.

//NOTE: but edge case: subarray len == 1 --> check if there exists even nums[i]

//NOTE: except for the 
#define Nonhead_Good(i) ( nums[i]<=threshold && ( nums[i]%2 != nums[i-1]%2 ) )
#include<algorithm>

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        
        int n = nums.size();

        vector<bool> nonhead_good(n);
        for(int i=1;i<n;i++) nonhead_good[i] = Nonhead_Good(i);

        //NOTE: edge case: subarray len == 1
        int max_win = 0;
        for(int i=0;i<n;i++)if(nums[i]%2==0 && nums[i]<=threshold){
            max_win = 1;
            break;
        }

        int right = 0, left = 1;
        while(right<n){
            while(left<n && !nonhead_good[left]) left++;
            right = left;
            while(right+1<n && nonhead_good[right+1]) right++;
            if(!(right<n)) break;


            if(nums[left]%2 == 0) max_win = max(max_win, right - (left-1) );
            else{
                max_win = max(
                    max_win,
                    right - (left-1) + (
                        (left-1>=0 && nums[left-1]<=threshold && nums[left-1]%2==0)?
                        1:(-1)
                    )
                );
            }

            //next
            left = right + 1;
        }

        return max_win;
    }
};
