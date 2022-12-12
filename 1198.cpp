#include<algorithm>
#include<assert.h>
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat.back().size();

        vector<int> row_idx(m, 0);
        int pre_row_front_max = INT_MIN;
        for(int i=0;i<m;i++)
            pre_row_front_max = max(pre_row_front_max, mat[i][0]);
        
        while(true){
            int row_front_max = INT_MIN;;
            for(int i=0;i<m;i++){
                //NOTE: for each row, go to where >= pre_row_front_max
                int j = row_idx[i];
                while(j < n && mat[i][j] < pre_row_front_max)j++;

                if(j == n)return (-1);//NOTE: no common element
                row_front_max = max(row_front_max, mat[i][j]);
            }

            //NOTE: can't improve
            if(row_front_max == pre_row_front_max)
                return row_front_max;
            pre_row_front_max = row_front_max;
        }
    }
};
