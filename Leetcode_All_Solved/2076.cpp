//m0
//why can't use uva war? because uva war is a bipartition.
//union find by rank with path compression in amortized O(1)
//totally in O(requests * restrictions) = O(10^6)
#define ROOT (-1)
class Solution {
public:
    vector<int> set;
    vector<int> rank;
    inline void make_set(const int& size){
        set.resize(size, ROOT);
        rank.resize(size, 1);
    }
    int set_find(const int& a){
        if(set[a] == ROOT) return a;
        return set[a] = set_find(set[a]);
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b) return;

        if(rank[a] < rank[b]) set[a] = b;
        else if(rank[a] > rank[b]) set[b] = a;
        else{
            set[a] = b;
            rank[b]++;
        }
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        make_set(n);
        vector<bool> ans;
        for(const vector<int>& f: requests){
            int f1 = set_find(f[0]);
            int f2 = set_find(f[1]);

            bool ans1 = true;
            for(const vector<int>& ban: restrictions){
                //NOTE: can't preprocess them, since set relations are changing.
                int ban1 = set_find(ban[0]);
                int ban2 = set_find(ban[1]);
                
                if( (f1==ban1 && f2==ban2) || (f2==ban1 && f1==ban2) ){
                    ans1 = false;
                    break;
                }
            }

            ans.push_back(ans1);
            if(ans1) set_join(f[0], f[1]);
        }

        return ans;
    }
};
