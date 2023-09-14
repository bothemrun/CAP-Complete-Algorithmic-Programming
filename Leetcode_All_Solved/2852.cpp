//m0
//dfs, O(n*n), but ok with disjoint set union.

#define maxn 300

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
};

class Solution {
public:
    int n;
    //fast init to 0 by array.
    bool visited[maxn][maxn] = {0};

    long long all_sum = 0;

    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};

    void dfs(const vector<vector<int>>& grid, const int& i, const int& j, long long& cnt, long long& sum){
        if(!(0<=i && i<n && 0<=j && j<n)) return;
        if(grid[i][j] == (-1)) return;

        if(visited[i][j]) return;
        visited[i][j] = true;

        all_sum += grid[i][j];

        cnt++;
        sum += grid[i][j];

        for(int k=0;k<di.size();k++){
            dfs(grid, i+di[k], j+dj[k], cnt, sum);
        }
    }

    long long sumRemoteness(vector<vector<int>>& grid) {
        n = grid.size();

        long long ans = 0;
        long long all_cnt = 0;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)if(visited[i][j] == false){
                long long cnt = 0;
                long long sum = 0;
                dfs(grid, i, j, cnt, sum);

                ans += sum * cnt;

                all_cnt += cnt;
            }

        return all_cnt * all_sum - ans;
    }
};
