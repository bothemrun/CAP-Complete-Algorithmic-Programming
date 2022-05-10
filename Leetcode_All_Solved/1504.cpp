#define max_size 152
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        vector<int> h(n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1) h[j]++;
                else h[j] = 0;
                
                if(h[j] == 0)continue;
                
                int min_h = max_size;
                for(int k=j;k>=0;k--){
                    if(h[k] < min_h) min_h = h[k];
                    if(min_h == 0)break;
                    
                    ans += min_h;
                }
            }
        }
        return ans;
    }
};
