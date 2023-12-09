//tree dp

//[A. recursion not healthy]

//1. pick root --> 
//1.a. values[root] + sum over subtrees{ max(true, false) }



//[B. recursion healthy]

//1. pick root
//1.a. values[root] + sum over subtree{ true }
//1.b. edge case: this root is a leaf.

//2. skip root -->
//2.a. 0 + sum of subtrees{ max(true, false) }

#define notyet (-1)
#include<algorithm>
#include<limits.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> al;
    vector<bool> leaf;
    
    vector<vector<long long>> memo;

    long long enum_healthy(const vector<int>& values, const int& root, bool healthy, const int& pre=(-1)){

        if(memo[root][healthy] != notyet) return memo[root][healthy];


        if(healthy == false){
            long long ret = values[root];
            for(const int& child: al[root])if(child != pre){
                ret += max(
                    enum_healthy(values, child, true, root),
                    enum_healthy(values, child, false, root)
                );
            }

            return memo[root][healthy] = ret;
        }else{
            //(choice 1. pick root)
            long long pick;
            if(leaf[root] == false){
                pick = values[root];
                for(const int& child: al[root])if(child != pre){
                    pick += enum_healthy(values, child, true, root);
                }
            }else{
                //not choose this choice
                pick = INT_MIN;
            }


            //(choice 2. skip root)
            long long skip = 0;
            for(const int& child: al[root])if(child != pre){
                skip += max(
                    enum_healthy(values, child, true, root),
                    enum_healthy(values, child, false, root)
                );
            }

            return memo[root][healthy] = max(pick, skip);
        }
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }

        const int root = 0;

        leaf.resize(n);
        if(n == 1) leaf[root] = true;

        for(int i=0;i<n;i++)if(i != root){
            leaf[i] = (al[i].size() == 1)? true:false;
        }


        memo.resize(n, vector<long long>(2, notyet));
        
        return enum_healthy(values, root, true);
    }
};
