//m1

//m0's while q.size() >= 2 not recommend & tricky, recommend using 310 minimum height tree's unpopped count.

//q.size() > 2 is wrong




//[A] crossed: 310. Minimum Height Trees
//(but easier, without returning the roots of MHT)

//[B] non-crossed: 1245. Tree Diameter

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

    int diameter_help(int& max_diameter, const vector<vector<int>>& al, int node, int par=(-1)){
        //without using a heap
        int prefix_max_child_depth = 0;

        for(const int& child: al[node])if(child != par){
            int child_depth = 1 + diameter_help(max_diameter, al, child, node);

            max_diameter = max(max_diameter, prefix_max_child_depth + child_depth);

            prefix_max_child_depth = max(prefix_max_child_depth, child_depth);
        }

        return prefix_max_child_depth;
    }

    int diameter(const vector<vector<int>>& al){
        int max_diameter = 0;
        diameter_help(max_diameter, al, 0);
        return max_diameter;
    }

    inline int mht(const vector<vector<int>>& al){
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
        //while q.size() >= 2 not recommended & tricky,
        //since q.size() > 2 is wrong.
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

        //310 minimum height trees: only 1 or 2 remained
        return level + ( (unpopped==2)? 1:0 );
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> al1, al2;
        make_al(edges1, al1);
        make_al(edges2, al2);

        return max({
            diameter(al1),
            diameter(al2),
            mht(al1) + 1 + mht(al2)
        });
    }
};
