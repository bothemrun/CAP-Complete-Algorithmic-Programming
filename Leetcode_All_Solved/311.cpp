//list of list of nonzero column elements, read official solution 2.
#include<tuple>
class Solution {
public:
    inline void list_of_list(const vector<vector<int>>& mat, vector<vector< tuple<int,int> >>& lis){
        int m = mat.size();
        int n = mat.back().size();

        lis.resize(m);

        for(int i=0;i<m;i++){
            vector< tuple<int,int> > row;
            
            for(int j=0;j<n;j++)if(mat[i][j] != 0)
                row.push_back( tuple<int,int>(j, mat[i][j] ) );
            
            lis[i] = row;
        }
    }

    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        vector<vector< tuple<int,int> >> list1;
        vector<vector< tuple<int,int> >> list2;
        list_of_list(mat1, list1);
        list_of_list(mat2, list2);

        int m = mat1.size();
        int n = mat2.back().size();
        vector<vector<int>> ans(m, vector<int>(n, 0) );

        for(int row1=0;row1<m;row1++)
            for(auto [col1, val1]: list1[row1])
                for(auto [col2, val2]: list2[col1] )
                    ans[row1][col2] += val1 *val2;

        return ans;
    }
};
