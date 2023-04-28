//m4
//smallest of fixed size implemented by min_element & setting min to INT_MAX without nth_element disturbing the order.
//O(n^2) bottom up dp.

//a column can't coincide with 2 columns of another row, so enough.
#define IDX(i) ((i)%2) //wrong: (i%2)
#define Memo(i) (memo[ IDX(i) ])
#include<algorithm>
#include<utility>

bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
    return a.first < b.first;
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        //edge case: n==1
        if(n < 2)return grid.front().front();

        vector<vector<pair<int,int>>> memo(2, vector<pair<int,int>>(n) );
        for(int j=0;j<n;j++) Memo(0)[j] = pair<int,int>(grid[0][j], j);

        for(int i=1;i<n;i++){
            
            pair<int,int>& s1 = *min_element(Memo(i - 1).begin(), Memo(i - 1).end(), cmp_fn );

            //NOTE: tmp like backtracking
            int s1_val = s1.first;
            s1.first = INT_MAX;
            pair<int,int> s2 = *min_element(Memo(i - 1).begin(), Memo(i - 1).end(), cmp_fn );
            s1.first = s1_val;
            
            for(int j=0;j<n;j++){
                Memo(i)[j] = pair<int,int>(
                    grid[i][j] + 
                    ( (s1.second==j)? s2.first:s1.first ),
                    j
                );
            }
        }

        return min_element(Memo(n-1).begin(), Memo(n-1).end(), cmp_fn )->first;
    }
};
