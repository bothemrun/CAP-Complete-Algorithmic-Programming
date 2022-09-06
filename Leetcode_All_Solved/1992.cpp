class Solution {
public:
    int m, n;
    vector<vector<int>> ans;
    inline bool out_or_forest(const vector<vector<int>>& land, int i, int j){
        if(!(0<=i && i<m && 0<=j && j<n))return true;
        if(land[i][j] == 0)return true;
        return false;
    }
    void dfs(vector<vector<int>>& land, int i, int j, int i_left, int j_top){
        if(out_or_forest(land, i, j))return;
        if(land[i][j] == 2)return;//visited farm
        
        land[i][j] = 2;//visit farm
        //check bottom right corner
        if(out_or_forest(land, i+1, j) && out_or_forest(land, i, j+1)) ans.push_back( vector<int>({i_left, j_top, i, j}) );
        
        dfs(land, i+1, j, i_left, j_top);
        dfs(land, i-1, j, i_left, j_top);
        dfs(land, i, j+1, i_left, j_top);
        dfs(land, i, j-1, i_left, j_top);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land.at(0).size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j] == 1)dfs(land, i, j, i, j);
            }
        }
        return ans;
    }
};
