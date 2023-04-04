//O(1) space as required by the follow-up.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.back().size();
        
        //NOTE: first check first row & column, then mark by inner cells
        //NOTE: the whole order is crucial
        bool row0_has0 = false;
        bool col0_has0 = false;
        for(int i=0;i<m;i++)if(!matrix[i][0]){
            col0_has0 = true;
            break;
        }
        for(int j=0;j<n;j++)if(!matrix[0][j]){
            row0_has0 = true;
            break;
        }

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(!matrix[i][j]){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)if(!matrix[i][0] || !matrix[0][j])
                matrix[i][j] = 0;
        
        if(col0_has0)
            for(int i=0;i<m;i++) matrix[i][0] = 0;
        if(row0_has0)
            for(int j=0;j<n;j++) matrix[0][j] = 0;
    }
};
