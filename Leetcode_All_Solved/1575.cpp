//m0
//recursion with memo. O(n*fuel*n)
#define notyet (-1)
#define mod ((int)1e9 + 7)
#define MOD(sum) ((sum>=mod)? (sum-mod):sum)
#include<algorithm>
#include<stdlib.h>

class Solution {
public:
    int n;
    int finish;
    vector<vector<int>> memo;
    int jump(const vector<int>& locations, const int& i, const int& fuel){
        if(fuel < 0) return 0;

        if(memo[i][fuel] != notyet) return memo[i][fuel];

        int ret = (i == finish);
        for(int j=0;j<n;j++)if(i != j)
            ret = MOD(
                ret +
                jump(locations, j, fuel - abs(locations[i] - locations[j] ) )
            );
        
        return memo[i][fuel] = ret;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        this->finish = finish;

        memo.resize(n, vector<int>(fuel + 1, notyet) );
        return jump(locations, start, fuel);
    }
};
