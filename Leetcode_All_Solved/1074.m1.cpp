//m1

//Thinking Process:
//[A] Dimension Reduction: 
//1. think of its 1D problem.

//[B] Fix a row band in O(n^2), can we do it in < O(m^2)?
//1. yes, think of the row band as the 1D line.
//2. so overall O(n^3) from O(n^4)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#define Pref(i, j) ( (i<0 || j<0)? 0:pref[i][j] )
#define submat(a, b, i, j) ( Pref(i, j) - Pref(i, b-1) - Pref(a-1, j) + Pref(a-1, b-1) )
//only use row_band_pref
#define row_band_pref(r1, r2, c) ( submat(r1, 0, r2, c) )

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.back().size();
        vector<vector<int>> pref(m, vector<int>(n));//no overflow
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                pref[i][j] = Pref(i-1, j) + Pref(i, j-1) - Pref(i-1, j-1) + matrix[i][j];
        
        
        int ans = 0;
        for(int r1=0;r1<m;r1++)
            for(int r2=r1;r2<m;r2++){
                //1D line problem
                unordered_map<int, int> pref_hash;
                pref_hash[0] = 1;//crucial
                
                for(int c=0;c<n;c++){
                    ans += pref_hash[ row_band_pref(r1, r2, c) - target ];
                    
                    //update
                    pref_hash[ row_band_pref(r1, r2, c) ]++;
                }
            }
        return ans;
    }
};