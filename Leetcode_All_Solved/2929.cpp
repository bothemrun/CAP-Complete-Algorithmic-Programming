//Thinking Process

//[A] Dimension Reduction
//1. naive O(n^2) as leetcode 2928 TLE.
//2. fix first child by a for loop.

//[B] Deal With 2 Children
//1. so j (children 1) + k (children 2) = remaining candies
//2. draw a picture.
//3. that is a simple line on the x-y plane.

//[C] Deal With The x-y plane
//1. also, the <= limit constraint is 1 horitonzal & 1 vertical line on the x-y plane.
//2. so find the intersections with [B], then simple.

//[C] complexity
// O(limit)

#include<algorithm>
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(long long i=0;i<=(long long)limit;i++){
            long long candy = (long long)n - i;
            if(candy < 0) continue;
            //j+k = candy
            
            long long x_left = candy - (long long)limit;
            long long x_right = (long long)limit;
            if(!(x_left <= x_right)) continue;
            
            if(x_left <= 0){
                //sum x from x=0 to x=candy
                ans += candy + 1;
            }else{
                ans += x_right - (x_left-1);
            }
        }
        
        return ans;
    }
};
