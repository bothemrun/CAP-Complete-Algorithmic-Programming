class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if(a==b && b==c) return "equilateral";

        for(int i=0;i<3;i++){
            if(nums[i]+nums[(i+1)%3] <= nums[(i+2)%3])
                return "none";
        }

        if(a==b || b==c || c==a) return "isosceles";

        return "scalene";
    }
};
