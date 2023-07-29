//m0
//recursion with memo.
//memo by hash map, since MLE for arrays.

//by expected value explanation of the editorial solution.
//https://leetcode.com/problems/soup-servings/editorial/

#define ceil_div(x, y) ((x%y==0)? x/y:(x/y + 1))
#include<unordered_map>
#include<algorithm>

class Solution {
public:
    unordered_map<int, unordered_map<int, double> > memo;

    double enum_p(int a, int b){
        a = max(0, a);
        b = max(0, b);

        if(a==0 && b==0) return 0.5;
        if(a==0) return 1.0;
        if(b==0) return 0;

        if(memo.count(a) != 0 && memo[a].count(b) != 0) return memo[a][b];

        double ret = (
            enum_p(a-4, b) +
            enum_p(a-3, b-1) +
            enum_p(a-2, b-2) +
            enum_p(a-1, b-3)
        )/4.0;
        return memo[a][b] = ret;
    }

    double soupServings(int n) {
        int m = ceil_div(n, 25);

        //bounding the ascending dp.
        for(int i=0;i<=m;i++)if( enum_p(i, i) >= 1.0 - 1e-5) return 1.0;

        return enum_p(m, m);
    }
};
