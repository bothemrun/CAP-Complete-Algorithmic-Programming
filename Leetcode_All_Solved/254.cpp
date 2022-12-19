#include<assert.h>
#include<unordered_map>
class Solution {
public:
    unordered_map<int, vector<int>> children;
    //children[*] ascending

    void factorize(const int& n, vector<bool>& dp_done){
        if(n == 1) return;
        assert(n > 1);
        if(dp_done[n] == true)return;

        children[n] = vector<int>();
        //NOTE: dedup,factors are non-decreasing
        for(int i=2;i <= n/i;i++)if(n%i == 0){
            //NOTE: i != 1, so exclude self
            factorize(n/i, dp_done);

            children[n].push_back(i);
        }

        //NOTE: self, children[n] still ascending
        children[n].push_back(n);

        dp_done[n] = true;
    }

    void tree_traverse_backtrack(const int& n, vector<vector<int>>& factors, vector<int>& factor1){
        if(n == 1){
            //pack
            factors.push_back(factor1);
            return;
        }
        assert(children.count(n) != 0);

        for(const int& child: children[n]){
            //NOTE: dedup,factors are non-decreasing
            if(factor1.size() != 0 && factor1.back() > child) continue;
            //NOTE: prune, including self
            if(!(n/child == 1 || child <= n/child))break;
            //NOTE: if factors non-increasing, don't have to check n/child == 1

            factor1.push_back(child);
            tree_traverse_backtrack(n/child, factors, factor1);
            factor1.pop_back();
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<bool> dp_done(n+1, false);
        
        factorize(n, dp_done);

        vector<vector<int>> factors;
        vector<int> factor1;
        tree_traverse_backtrack(n, factors, factor1);

        //NOTE: exclude self, but when factored, sub-factors include themselves
        factors.pop_back();
        return factors;
    }
};
