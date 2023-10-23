//the topmost key is that "no string is a substring of another string".
//so we don't have to consider overlapping with previous previous strings.
//therefore we can have pairwise edge weights.

//traveling salesperson problem.
//first pre-compute graph weights.

//backtracking with O(n!).
//a lot of overlapping subproblems

//but bitmask dp takes O((2^n) * n) = 
//O((2^20 * 20)) = O(2e7)
//recursion with memo


//edge case:
//["ab","a","b"]
//which violates the problem description that "no string is a substring of another string".

#define no_parent (-2)
#include<algorithm>
#include<assert.h>
#include<limits.h>

class Solution {
public:
    int n;
    vector<vector<int>> graph;

    vector<vector<bool>> done;
    vector<vector<int>> memo;
    vector<vector<int>> parent;

    inline int concat_cost(const string& a, const string& b){
        int asize = a.size(), bsize = b.size();
        int cost = bsize;

        //NOTE: no substring relationship
        //for(int overlap=1; overlap<min(asize, bsize); overlap++){
        //edge case:
        //["ab","a","b"]
        //which violates the problem description that "no string is a substring of another string".
        for(int overlap=1; overlap <= min(asize, bsize); overlap++){
            if( a.substr(asize - overlap) == b.substr(0, overlap) )
                cost = bsize - overlap;
        }

        return cost;
    }

    void enum_pre(const vector<string>& words, const int& mask, const int& cur){
        if(__builtin_popcount(mask) == 1){
            done[mask][cur] = true;
            memo[mask][cur] = words[cur].size();
            parent[mask][cur] = no_parent;
            return;
        }

        if(done[mask][cur]) return;


        bool parent_updated = false;
        int cost = INT_MAX;
        int pre_mask = (mask & (~(1<<cur)) );
        for(int pre=0;pre<n;pre++)if(pre != cur){
            if( ( (1<<pre) & pre_mask ) == 0) continue;

            enum_pre(words, pre_mask, pre);
            int new_cost = memo[pre_mask][pre] + graph[pre][cur];
            if(new_cost < cost){
                cost = new_cost;

                parent[mask][cur] = pre;
                parent_updated = true;
            }
        }

        assert(parent_updated);
        memo[mask][cur] = cost;
        done[mask][cur] = true;
        return;
    }

    string shortestSuperstring(vector<string>& words) {
        n = words.size();

        graph.resize(n, vector<int>(n));

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)if(i != j)
                graph[i][j] = concat_cost(words[i], words[j]);

        
        done.resize(1<<n, vector<bool>(n, false));
        memo.resize(1<<n, vector<int>(n));
        parent.resize(1<<n, vector<int>(n));
        const int full_mask = (1<<n) - 1;

        for(int cur=0;cur<n;cur++)
            enum_pre(words, full_mask, cur);
        

        int cur = distance(
            memo[full_mask].begin(),
            min_element( memo[full_mask].begin(), memo[full_mask].end() )
        );
        string ans = words[cur];
        int mask = full_mask;

        while(mask != 0){
            int pre = parent[mask][cur];
            if(pre == no_parent) break;

            //concat forwards
            int overlap = (int)words[cur].size() - graph[pre][cur];
            int pre_remain = (int)words[pre].size() - overlap;
            ans = words[pre].substr(0, pre_remain) + ans;

            //update
            mask = ( mask & (~(1<<cur)) );
            cur = pre;
        }

        return ans;
    }
};
