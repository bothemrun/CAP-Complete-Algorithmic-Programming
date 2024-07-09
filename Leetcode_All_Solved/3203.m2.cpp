//m2

//[A] crossed: 310. Minimum Height Trees
//(but easier, without returning the roots of MHT)

//[B] non-crossed: 1245. Tree Diameter


//[C] roots (1 or 2) of the minimum height trees by topological sort == middle nodes of the diameter

//1. so mht = ceiling(diameter / 2)
//2. use diameter dfs method for mht.

#define ceil_div(a, b) ( a/b + ( (a%b==0)? 0:1 ) )
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
        //so don't need a heap
        int prefix_max_child_d = 0;

        for(const int& child: al[node])if(child != par){
            int child_d = 1 + diameter_help(max_diameter, al, child, node);

            max_diameter = max(max_diameter, prefix_max_child_d + child_d);

            prefix_max_child_d = max(prefix_max_child_d, child_d);
        }

        return prefix_max_child_d;
    }

    int diameter(const vector<vector<int>>& al){
        int max_diameter = 0;
        diameter_help(max_diameter, al, 0);

        return max_diameter;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> al1, al2;
        make_al(edges1, al1);
        make_al(edges2, al2);

        int diameter1 = diameter(al1);
        int mht1 = ceil_div(diameter1, 2);

        int diameter2 = diameter(al2);
        int mht2 = ceil_div(diameter2, 2);

        return max({diameter1, diameter2, mht1 + 1 + mht2 });
    }
};
