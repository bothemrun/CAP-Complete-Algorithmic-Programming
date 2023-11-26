class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat.back().size();
        k %= n;
        for(int i=1;i<m;i+=2){
            //odd rows to the right
            for(int j=0;j<n;j++){
                if( mat[i][j] != mat[i][ (j+k)%n ] ){
                    return false;
                }
            }
        }
        for(int i=0;i<m;i+=2){
            //even rows left
            for(int j=0;j<n;j++){
                if( mat[i][j] != mat[i][ ( (j-k)%n + n)%n ] ){
                    return false;
                }
            }
        }
        
        return true;
    }
};
