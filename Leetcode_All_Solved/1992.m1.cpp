//m1
class Solution {
public:
    int m, n;
    inline bool out_or_forest(const vector<vector<int>>& land, int i, int j){
        if(!(0<=i && i<m && 0<=j && j<n))return true;
        if(land[i][j] == 0)return true;
        return false;
    }
    vector<vector<int>> ans;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land.at(0).size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j] == 0)continue;
                if(out_or_forest(land, i-1, j) && out_or_forest(land, i, j-1)){
                    int i_bottom = i, j_right = j;
                    while(out_or_forest(land, i_bottom+1, j) == false) i_bottom++;
                    while(out_or_forest(land, i, j_right+1) == false) j_right++;
                    ans.push_back( vector<int>({i, j, i_bottom, j_right}) );
                }
            }
        }
        return ans;
    }
};
