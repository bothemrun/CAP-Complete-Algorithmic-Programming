//m3
//smallest of fixed size by nth_element(), O(n^2) bottom up dp.
#define IDX(i) ((i)%2) //wrong: (i%2)
#define Memo(i) (memo[ IDX(i) ])
#include<algorithm>
#include<utility>

bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
    return a.first < b.first;
}

class Solution {
public:
    vector<vector<pair<int, int>>> memo;
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        //edge case: n==1
        if(n < 2) return grid.front().front();

        memo.resize(2, vector<pair<int,int>>(n) );
        for(int j=0;j<n;j++) Memo(0)[j] = pair<int,int>(grid[0][j], j);

        for(int i=1;i<n;i++){
            pair<int,int> s1 = *min_element(Memo(i - 1).begin(), Memo(i - 1).end(), cmp_fn );;
            
            nth_element(Memo(i - 1).begin(), Memo(i - 1).begin() + 1, Memo(i - 1).end(), cmp_fn );
            pair<int,int> s2 = Memo(i - 1).at(1);

            for(int j=0;j<n;j++){
                Memo(i)[j] = pair<int,int>(
                    grid[i][j] + 
                    ( (j == s1.second)? s2.first:s1.first ),
                    j
                );
            }
        }

        return min_element(Memo(n-1).begin(), Memo(n-1).end() )->first;
    }
};
