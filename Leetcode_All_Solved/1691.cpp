//m0
//m := 6n, O(m^2)
#include<algorithm>

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<vector<int>> cub;
        
        for(int i=0;i<n;i++){
            vector<int> p({0,1,2});

            do{
                vector<int> cub1;
                for(const int& pp: p) cub1.push_back(cuboids[i][pp] );
                cub1.push_back(i);

                cub.push_back(cub1);
            }while( next_permutation(p.begin(), p.end()) );
        }

        sort(cub.begin(), cub.end());

        //NOTE: longest increasing subsequence
        int m = cub.size();
        int max_lis = 0;
        vector<int> memo(m);
        for(int i=0;i<m;i++){
            memo[i] = cub[i][0];

            for(int j=0;j<i;j++)if( 
                cub[j][0]<=cub[i][0] && 
                cub[j][1]<=cub[i][1] && 
                cub[j][2]<=cub[i][2] && 
                cub[j][3]!=cub[i][3] )
                memo[i] = max(
                    memo[i],
                    memo[j] + cub[i][0]
                );
            
            max_lis = max(max_lis, memo[i]);
        }
        return max_lis;
    }
};
