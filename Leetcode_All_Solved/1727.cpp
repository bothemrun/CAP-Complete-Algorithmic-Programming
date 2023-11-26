//Thinking Process

//[A] Consecutive 1s:
//1. in each column
//2. of course easy.


//[B] Dimension Reduction: Fix A Bottom:
//1. count heights of 1s for each column.
//2. sort the heights.
//3. in O(n), enumerate all rectangles.
//4. takes O(m*nlogn)


//[C] Extend [B] to General Dimension
//1. easy. for each column, use two pointer.
//2. then we only traverse the matrix once in O(m*n)
//3. optim: matrix loop: row first then columns

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.back().size();

        vector<vector<int>> height(m, vector<int>(n));
        //optim: matrix loop: row first then columns
        for(int j=0;j<n;j++) height[0][j] = matrix[0][j];

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0)
                    height[i][j] = 0;
                else height[i][j] = 1 + height[i-1][j];
            }
        }


        int ans = 0;
        //NOTE: Dimension Reduction: Fix a Bottom
        for(int i=0;i<m;i++){
            sort(height[i].begin(), height[i].end());

            for(int j=0;j<n;j++){
                int width = (n-1) - (j-1);
                ans = max(ans, height[i][j] * width);
            }
        }

        return ans;
    }
};
