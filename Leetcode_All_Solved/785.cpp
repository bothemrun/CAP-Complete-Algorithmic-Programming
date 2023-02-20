//uva10158 War
class Solution {
public:
    int n;
    int set_find(vector<int>& set, const int& a){
        if(set[a] == (-1))return a;
        return set[a] = set_find(set, set[a]);
    }
    void set_join(vector<int>& set, int a, int b){
        a = set_find(set, a);
        b = set_find(set, b);
        if(a != b) set[a] = b;
        //NOTE: if a & b from same set, and a is the root
    }

    void set_enemy(vector<int>& set, const int& a, const int& b){
        set_join(set, a, b+n);
        set_join(set, a+n, b);
    }

    int relation(vector<int>& set, const int& a, const int& b){
        if(set_find(set, a) == set_find(set, b+n))return 1;//enemy
        else if(set_find(set, a) == set_find(set, b))return 0;//friend
        else return 2;//undetermined
    }

    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> set(2*n, (-1));
        for(int u=0;u<n;u++){
            for(const int& v: graph[u]){
                if(relation(set, u, v) == 0){
                    //friends
                    return false;
                }

                set_enemy(set, u, v);
            }
        }

        return true;
    }
};
