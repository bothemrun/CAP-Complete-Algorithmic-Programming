//m3

//[A] crossed: 310. Minimum Height Trees
//(but easier, without returning the roots of MHT)

//[B] non-crossed: 1245. Tree Diameter


//[C] roots (1 or 2) of the minimum height trees by topological sort == middle nodes of the diameter

//1. so diameter = mht*2 + possibly 1
//2. use mht's topological sort method for diameter.

#define tii tuple<int,int>
#include<tuple>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline void make_al(const vector<vector<int>>& edges, vector<vector<int>>& al){
        int n = edges.size() + 1;
        al.resize(n);
        for(const vector<int>& e: edges){
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
    }

    inline tii mht(const vector<vector<int>>& al){
        int n = al.size();

        queue<int> q;
        vector<bool> ever2q(n, false);

        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++){
            indegree[i] = al[i].size();

            if(indegree[i] == 1){
                q.push(i);
                ever2q[i] = true;
            }
        }

        int level = 0;

        //wrong: while(q.size() > 2){
        //NOTE: tricky, not recommended.
        //recommend using unpopped count in 310. Minimum Height Trees.
        //not recommended:  while(q.size() >= 2){
        int unpopped = n;
        while(unpopped > 2){
            level++;

            int qsize = q.size();
            for(int l=0;l<qsize;l++){
                int u = q.front();
                q.pop();

                unpopped--;

                for(const int& v: al[u])if(ever2q[v] == false){
                    if(--indegree[v] == 1){
                        q.push(v);
                        ever2q[v] = true;
                    }
                }
            }
        }

        return {level + ( (unpopped==2)? 1:0 ), unpopped==2};
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> al1, al2;
        make_al(edges1, al1);
        make_al(edges2, al2);

        auto [mht1, mid1] = mht(al1);
        int diameter1 = mht1*2 - mid1;

        auto [mht2, mid2] = mht(al2);
        int diameter2 = mht2*2 - mid2;

        return max({diameter1, diameter2, mht1 + 1 + mht2 });
    }
};
