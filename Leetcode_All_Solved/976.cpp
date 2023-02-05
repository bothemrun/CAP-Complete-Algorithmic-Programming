//NOTE: it can be proved that for a <=b <= c, c < a+b guarantees b < a+c & a < b+c
//so if c < a+b, then (a,b,c) forms a legal triangle
//if c >= a+b, then (a,b,c) doesn't.

//NOTE: so if neighboring (a,b,c) doesn't have c < a+b, then smaller (a,b) won't either.

//NOTE: so in decreasing order of c, check neighboring (a,b,c).
#include<algorithm>
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=n-1;i-2>=0;i--){
            if(nums[i-2] + nums[i-1] > nums[i])
                return nums[i] + nums[i-1] + nums[i-2];
        }

        return 0;
    }
};
