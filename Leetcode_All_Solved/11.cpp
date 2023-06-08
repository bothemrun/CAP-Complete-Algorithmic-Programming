//SOSG: I read intuition & proof from:
//https://leetcode.com/problems/container-with-most-water/solutions/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm/
//his matrix visualization is great.
#include<algorithm>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_area = 0;
        int left = 0, right = n-1;
        while(left < right){
            max_area = max(
                max_area,
                min(height[left], height[right]) *
                ( right - left )
            );

            if(height[left] < height[right]) left++;
            else right--;
        }

        return max_area;
    }
};
