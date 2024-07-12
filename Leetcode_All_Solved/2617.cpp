//m0

//online skyline problem 218.

//3960ms 5.16%, sometimes TLE.
//but wisdompeak's line sweep implemented by priority queue: 1237ms 26%.


//[A] brute force:

//1. clearly DP.
//2. for each dp[i][j] to update dp[i][j+1] ~ dp[i][j+g] --> O(mn * max(m, n)) TLE.


//[B] observe:

//1. update dp(i, j+1 ~ j+g) --> interval problem.


//[C] interval problem?

//1. but non-additive / comparative line sweep --> the skyline problem 218.

//2. but online skyline problem, so line sweep implemented by sorting is not applicable.

//3. for each rows & cols, maintain m*n skyline problems.

//4. can't use top down DP, 'cuz it's online.


//O(mn * skyline problem) = O(mn * (logm + logn) )

#define inf_add(a, b) ( (a==impossible || b==impossible)? impossible:(a+b) )

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.back().size();

        const int impossible = INT_MAX;
        vector<vector<int>> memo(m, vector<int>(n, impossible));
        memo[0][0] = 1;
        
        //skyline problems, line sweep
        vector< map<int, vector<int>> > row2line(m);
        vector< map<int, vector<int>> > col2line(n);
        //skyline problems, sweep
        vector< multiset<int> > row2sweep(m);
        vector< multiset<int> > col2sweep(n);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //update sweep for buildings currently on
                //row-wise
                for(const int& h: row2line[i][j]){
                    if(h>0){
                        row2sweep[i].insert(h);
                    }else{
                        //erase(val) erases all isntances with val
                        row2sweep[i].erase( row2sweep[i].find( -h ) );
                    }
                }
                //col-wise
                for(const int& h: col2line[j][i]){
                    if(h>0){
                        col2sweep[j].insert(h);
                    }else{
                        //erase(val) erases all isntances with val
                        col2sweep[j].erase( col2sweep[j].find( -h ) );
                    }
                }

                //check the skyline in currently on sweep
                if(row2sweep[i].size()){
                    memo[i][j] = min(memo[i][j], *row2sweep[i].begin() );
                }
                if(col2sweep[j].size()){
                    memo[i][j] = min(memo[i][j], *col2sweep[j].begin() );
                }


                //add a building with a interval, with the newly updated dp val.
                const int& jump = grid[i][j];

                //may be impossible to reach.
                const int new_h = inf_add(1, memo[i][j] ); //1 + memo[i][j];

                if(jump >= 1){
                    //add a building with row-wise intervals
                    row2line[i][ j+1 ].push_back(new_h);
                    row2line[i][ j+1+jump ].push_back( -new_h );
                    //add a building with col-wise intervals
                    col2line[j][ i+1 ].push_back(new_h);
                    col2line[j][ i+1+jump ].push_back( -new_h );
                }
            }
        }

        if(memo[m-1][n-1] == impossible) return (-1);
        return memo[m-1][n-1];
    }
};
