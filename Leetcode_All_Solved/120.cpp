#include<algorithm>
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp_row[n];
        int dp_prev_row[n];
        if(n == 1)return triangle[0][0];
        dp_prev_row[0] = triangle[0][0];
        for(int row=1;row<n;row++){
            dp_row[0] = dp_prev_row[0] + triangle[row][0];
            dp_row[row] = dp_prev_row[row-1] + triangle[row][row];
            for(int i=1;i<row;i++)
                dp_row[i] = min(dp_prev_row[i], dp_prev_row[i-1]) + triangle[row][i];
            
            //dp with saving space
            for(int i=0;i<=row;i++)//note the upper bound
                dp_prev_row[i] = dp_row[i];
        }
        
        int min_path = dp_row[0];
        for(int i=0;i<n;i++) min_path = min(min_path, dp_row[i]);
        return min_path;
    }
};
