//NOTE: 231. Power of Two for p[0] and p.back() bit comparison
#include<assert.h>
class Solution {
public:
    bool backtrack(const int& n, const int& p_max_size, vector<bool>& visited, vector<int>& p, int u){
        if(p.size() == p_max_size){
            //NOTE: 231. Power of Two
            long long diff = p.front() ^ p.back();
            long long rightmost_1bit = (~diff + 1) & diff;
            return rightmost_1bit == diff;
        }

        if(visited[u])return false;
        
        visited[u] = true;
        p.push_back(u);

        int mask = 1;
        for(int b=0;b<n;b++){
            int v = (u & ~mask) | ( ~(u & mask) & mask);

            if(backtrack(n, p_max_size, visited, p,  v) == true)return true;

            mask <<= 1;
        }

        //backtrack
        visited[u] = false;
        p.pop_back();
        return false;
    }

    vector<int> circularPermutation(int n, int start) {
        int p_max_size = (1 << n) - 1 + 1;
        vector<bool> visited(p_max_size, false);
        vector<int> p;
        bool ret = backtrack(n, p_max_size, visited, p, start);
        assert(ret);
        return p;
    }
};
