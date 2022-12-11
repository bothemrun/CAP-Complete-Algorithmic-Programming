//m1
//much clear than long ago
#include<algorithm>
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat.back().size();
        int cnt = 0;

        vector<int> height(n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //NOTE: maintain height
                if(mat[i][j] == 1) height[j]++;
                else height[j] = 0;

                //NOTE: for bottom right corner (i, j)
                int suffix_min_height = height[j];
                for(int k=j;k>=0;k--){
                    suffix_min_height = min(suffix_min_height, 
                        height[k]);
                    
                    if(suffix_min_height == 0)break;
                    
                    cnt += suffix_min_height;
                }
            }
        }

        return cnt;
    }
};
