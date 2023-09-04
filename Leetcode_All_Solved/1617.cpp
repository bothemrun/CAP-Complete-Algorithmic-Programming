//instead of from all distances d to find number subtrees,
//we go from all subtrees to get its distance d, and count 1 subtree for that distance d.

//O(enumerate by subtrees) * O(dfs to check connectedness + postorder for tree diameter)
// = O(2^n * n) = O(2^15 * 15) = O(3e4 * 15) = O(5e5)

//enumerate all subtrees / subsets by bitmask



//tree diameter by prefix max depth
//without fixed size priority queue
//Ref: 1245. Tree Diameter votrubac : https://leetcode.com/problems/tree-diameter/solutions/420452/c-with-picture-o-n/


#include<assert.h>
#include<algorithm>

class Solution {
public:
    int n;
    vector<vector<int>> al;

    inline int get_root(const int& mask){
        for(int i=0, bit=1;i<n;i++, bit<<=1)if( mask & bit )
            return i;
        assert(false);
    }

    int dfs_connected(const int& u, int& visited, const int& mask){
        if( !( mask & (1<<u) ) ) return 0;

        if(visited & ( 1<<u ) ) return 0;
        visited |= ( 1<<u );

        int cnt = 1;
        for(const int& v: al[u])
            cnt += dfs_connected(v, visited, mask);
        return cnt;
    }

    inline bool connected(const int& mask){
        //gcc standard, but c++20 will have std popcount()
        int cnt = __builtin_popcount(mask);

        int root = get_root(mask);

        int visited = 0;
        return cnt == dfs_connected(root, visited, mask);
    }


    int diameter_by_prefix_max_depth(const int& u, int& diameter, const int& mask, const int& parent=(-1)){
        //NOTE: this method doesn't need fixed size priority queue.

        int prefix_max_depth = 0;
        for(const int& v: al[u])if( v != parent && ( mask & (1<<v) ) ){
            int cur_depth = diameter_by_prefix_max_depth(v, diameter, mask, u);

            diameter = max(diameter, cur_depth + prefix_max_depth);

            prefix_max_depth = max(prefix_max_depth, cur_depth);
        }
        return prefix_max_depth + 1;
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        this->n = n;

        al.resize(n);
        //all to 0-indexed
        for(const vector<int>& e: edges){
            al[e[0] - 1].push_back(e[1] - 1);
            al[e[1] - 1].push_back(e[0] - 1);
        }


        vector<int> diameter2subtree(n-1, 0);

        const int max_mask = ( (1<<n) - 1 );
        for(int mask=1;mask<=max_mask;mask++){
            //gcc standard, but c++20 will have std popcount()
            if( __builtin_popcount(mask) == 1) continue;
            
            if( connected(mask) == false ) continue;

            int diameter = 0;
            diameter_by_prefix_max_depth( get_root(mask), diameter, mask );

            assert(1<=diameter && diameter <=n-1);
            diameter2subtree[ diameter - 1 ]++;
        }

        return diameter2subtree;
    }
};
