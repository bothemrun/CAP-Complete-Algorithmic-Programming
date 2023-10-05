//O(n) one pass

//(a) illegal sources:
//(a.1) double parent
//(a.2) cycle
//(a.3) both of 1 & 2

//(b) if (a.1) happens, then must remove 1 of the 2 parents
//so (a.3) included in this case



//(c) three cases of double parents (a.1):
//(c.1) connect 2 different paths
//(c.2) connect the same path downwards
//(c.3) connect the same path upwards

//for (c.1) & (c.2), removing any of the 2 double parents will form a valid tree (and both connected), so return the later one.

//for (c.3), the removal will have exactly: 1 valid tree & 1 disconnected component.
//so just check for connectivity.


//if no double parents, then (a.2), also check connectivity on the way.
//the case is when the extra edge is pointed to the root.
//can't just return the last edge.


//(d) finally, one pass implementation can be done by the rules above.

#include<assert.h>

class Solution {
public:
    vector<int> dsu;
    vector<int> rank;
    vector<int> cnt;
    inline void make_set(const int& size){
        dsu.resize(size);
        for(int i=0;i<size;i++) dsu[i] = i;

        rank.resize(size);
        cnt.resize(size, 1);
    }
    int set_find(const int& a){
        if(dsu[a] == a) return a;
        return dsu[a] = set_find(dsu[a]);
    }
    inline bool set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b) return false;

        if(rank[a] < rank[b]){
            dsu[a] = b;

            cnt[b] += cnt[a];
        }else if(rank[a] > rank[b]){
            dsu[b] = a;

            cnt[a] += cnt[b];
        }else{
            dsu[a] = b;

            cnt[b] += cnt[a];

            rank[b]++;
        }

        return true;
    }
    inline bool is_connected(){
        return cnt[ set_find(0) ] == (int)cnt.size();
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        const int no_parent = (-1);
        vector<int> parent(n, no_parent);

        vector<vector<int>> dup_parent;
        vector<int> delete_edge;

        for(const vector<int>& e: edges){
            int u = e[0]-1;
            int v = e[1]-1;

            if(parent[v] != no_parent){
                dup_parent = { { parent[v] + 1, v + 1 } , e};

                //NOTE: delete the second
                delete_edge = e;

                break;
            }

            parent[v] = u;
        }


        make_set(n);
        for(const vector<int>& e: edges)if(e != delete_edge){
            int u = e[0]-1;
            int v = e[1]-1;

            if(
                set_join(u, v) == false &&
                dup_parent.size() == 0
            ) return e;
        }

        assert(dup_parent.size() != 0);

        if(is_connected() == true)
            return dup_parent.back();
        else
            return dup_parent.front();
    }
};
