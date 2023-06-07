//m0
//grow upwards, then grow leftwards & rightwards. O(n^3)
//NOTE: method m1 will improve m0 to O(n^2)
#include<algorithm>
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix.back().size();

        int max_rec = 0;
        vector<int> height(n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                height[j] = (matrix[i][j]=='1')? (height[j]+1):0;


            for(int j=0;j<n;j++){
                //NOTE: find left & right bound above this height
                //NOTE: method m1 will improve this
                int left = j;
                while(left-1>=0 && height[left-1] >= height[j]) left--;
                int right = j;
                while(right+1<n && height[j] <= height[right+1]) right++;

                max_rec = max(max_rec, height[j] * (right - (left-1)) );
            }
        }

        return max_rec;
    }
};
