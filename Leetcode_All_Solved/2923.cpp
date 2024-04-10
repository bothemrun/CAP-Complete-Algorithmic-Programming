//O(n^2)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){

                if(grid[i][j] == 1)
                    indegree[j]++;
                else
                    indegree[i]++;
            }

        for(int i=0;i<n;i++)if(indegree[i] == 0)
            return i;
        assert(false);
        return (-1);
    }
};
