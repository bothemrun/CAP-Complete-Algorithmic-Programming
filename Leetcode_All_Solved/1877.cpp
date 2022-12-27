//NOTE:
//suppose we've already split into 2 arrays

//(1) [compare between the same arr]
//if a<b in arr1, x<y in arr2, 
// compare max(a+x, b+y) ? max(a+y, b+x)
// since max(a+x, b+y) == b+y ? max(a+y, b+x)
// since b+y > a+y && b+y > b+x,
// so mismatch is better.

//(2) [compare between arrays]
//now we have ascending arr1 & descending arr2
// arr1: a < b, arr2: y > x
// first swap a & y is meaningless since a+y == y+a, so now we consider swapping a & x 
// (we have considered swapping a & b in (1) )
//without loss of generality, assume a > x
// now compare y & b,
// if(y > b), then it's large+large (a+y) 
//formally, max(a+y,b+x) == a+y ? max(a+b, y+x) (compare with swapping y & b)
// since a+y > both of a+b and y+x due to y>b & a>x respectively
// so y < b is better.

//(3) in conclusion, ascending arr1 all > descending arr2, is the best.

#include<limits.h>
#include<algorithm>
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int max_pair = INT_MIN;
        for(int i=0;i<n/2;i++)
            max_pair = max(max_pair, nums[i] + nums[n - 1 - i] );
        return max_pair;
    }
};
