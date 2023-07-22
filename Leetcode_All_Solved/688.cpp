//m0
//recursion with memo.
//O(n*n * k) = O(6e4)

#define notyet (-1)

class Solution {
public:
    int n;
    vector<int> di, dj;

    vector<vector<vector<double>>> memo;

    double enum8(const int& i, const int& j, const int& remain){
        if(!(0<=i && i<n && 0<=j && j<n)) return 0;
        if(remain == 0) return 1;

        if(memo[i][j][remain] != notyet) return memo[i][j][remain];

        double ret = 0;
        for(int k=0;k<di.size();k++){
            ret += enum8(
                i + di[k],
                j + dj[k],
                remain - 1
            );
        }
        return memo[i][j][remain] = ret / 8.0;
    }

    double knightProbability(int n, int k, int row, int column) {
        this->n = n;

        vector<int> two = {2, -2};
        vector<int> one = {1, -1};
        for(const int& i: two)
            for(const int& j: one){
                di.push_back(i);
                dj.push_back(j);
            }
        for(const int& i: one)
            for(const int& j: two){
                di.push_back(i);
                dj.push_back(j);
            }


        //remain is 1-indexed
        memo.resize(n, vector<vector<double>>(n, vector<double>(k + 1, notyet)) );

        return enum8(row, column, k);
    }
};
