//prefix hash to reduce time from O(n^4) to O(n^3)
#define Prefix(i, j) ( (0<=i && 0<=j)? prefix_sum[i][j]:0 )
#define Rowband_Prefix(r1, r2, c2) ( Prefix(r2, c2) - Prefix(r1-1, c2) )

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.back().size();
        vector<vector<int>> prefix_sum(m, vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                prefix_sum[i][j] = matrix[i][j] + Prefix(i-1, j) + Prefix(i, j-1) - Prefix(i-1, j-1);
        
        int cnt = 0;
        //upper left:(r1, c1), lower right:(r2, c2), inclusive
        for(int r1=0;r1<m;r1++)
        for(int r2=r1;r2<m;r2++){
            //NOTE: prefix hash to reduce time complexity
            unordered_map<int, int> rowband_prefix_hash;

            //NOTE: desired rectangle == rowband prefix
            rowband_prefix_hash[0] = 1;//NOTE: key

            for(int c2=0;c2<n;c2++){
                int want_prefix_hash = Rowband_Prefix(r1, r2, c2) - target;

                if(rowband_prefix_hash.count(want_prefix_hash) != 0)
                    cnt += rowband_prefix_hash[want_prefix_hash];
                
                //update
                rowband_prefix_hash[ Rowband_Prefix(r1, r2, c2) ]++;
            }
        }

        return cnt;
    }
};
