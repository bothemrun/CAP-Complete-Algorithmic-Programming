//m2
//m1 + pruning
#define prune 1
#include<assert.h>
#include<unordered_map>
class Solution {
public:
    unordered_map<int, vector<int>> children;

    void factorize(const int& n, vector<bool>& dp_done){
        if(n == 1)return;
        assert(n > 1);

        if(dp_done[n] == true)return;

        children[n] = vector<int>();

        //NOTE: prune by i*i <= n
        //NOTE: i != 1, or infinite loops
        for(int i=2;i*i<=n;i++)if(n%i == 0){
            factorize(n/i, dp_done);

            children[n].push_back(i);
        }

        //NOTE: self, for primes
        children[n].push_back(n);

        dp_done[n] = true;
    }

    void tree_traverse_backtrack(const int& n, const int& self, vector<vector<int>>& factors, vector<int>& factor1){
        if(n == 1){
            if(n == self)return;

            //pack
            factors.push_back(factor1);
            return;
        }
        assert(n > 1);

        //NOTE: child==self --> infinite loops
        for(const int& child: children[n])if(child != self){
            
            //NOTE: dedup, both nondecreasing / nonincreasing are ok --> Wrong !!
            //NOTE: for back() >= child, factorize() needs to go from n-1~2, not from n-1~sqrt(n)
            //NOTE: so why <= can go from 2~sqrt(n)?
            //NOTE: 'cuz 2~sqrt(n) satisfies decomposability.
            //for eg., for 6, must have visited 2, 6 <= 6
            //NOTE: but n-1~sqrt(n) doesn't satisfy decomposability.
            //for eg., for 6, we may not visit 2, 3.
            if(factor1.size() != 0 && !(factor1.back() <= child) )continue;

            #if prune == 1
            //if(child > n/child)break;
            if(n/child != 1 && child > n/child)break;
            #endif

            factor1.push_back(child);
            tree_traverse_backtrack(n/child, self, factors, factor1);
            factor1.pop_back();
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<bool> dp_done(n+1, false);
        factorize(n, dp_done);

        vector<vector<int>> factors;
        vector<int> factor1;
        tree_traverse_backtrack(n, n, factors, factor1);
        return factors;
    }
};
