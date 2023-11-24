// Greedy Proof

//[A] think about the leftmost part.
//1. can I expand rightwards as much as possible?
//2. if 1 element is removed from the 2nd part, then the 2nd part's gcd won't decrease.

//[B] recursion
//1. keep using [A] from left to right, we prove by indcution/recursion.

#include<numeric> //gcd()

class Solution {
public:
    int minimumSplits(vector<int>& nums) {
        int ans = 1;//for the ending

        int cur_gcd = nums.front();
        for(const int& x: nums){
            int new_gcd = gcd(cur_gcd, x);

            if(new_gcd == 1){
                //this element as a new part.
                ans++;

                cur_gcd = x;
            }else{
                //keep the current part
                cur_gcd = new_gcd;
            }
        }

        return ans;
    }
};
