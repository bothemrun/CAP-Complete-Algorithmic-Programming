//m0
//[A] O(n^2) by dp from O(3^n) dfs.

//[B] memo data types:
//1. dp(i, prev_pos) --> vector< hash map > but still need hash map of pos to i
//2. dp(i, prev_i) + hash map of pos to i.

class Solution {
public:
    int n;
    const int notyet = (-1);
    vector<vector<int>> memo;

    unordered_map<int,int> pos2i;

    bool enum3(const vector<int>& pos, int i, int prev_i){
        if(i==n-1) return true;

        if(memo[i][prev_i] != notyet) return memo[i][prev_i];

        const int k = pos[i] - pos[prev_i];
        bool ret = false;
        for(const int jump: {k-1, k, k+1})if(jump>0 && pos2i.count( pos[i] + jump ) != 0){
            ret |= enum3(pos, pos2i[ pos[i] + jump ], i);

            if(ret) break;
        }
        return memo[i][prev_i] = ret;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();

        for(int i=0;i<n;i++) pos2i[stones[i]] = i;

        memo.resize(n, vector<int>(n, notyet));
        //trick: i=0, k=stones[0]-stones[0]=0, {-1, 0, +1}
        return enum3(stones, 0, 0);
    }
};
