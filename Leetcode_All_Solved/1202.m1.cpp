//m1
//connected component / parent by union find by rank with path compression, amortized O(1)
//only 1 sort, instead of 2 sort, for smallest string
#define ROOT (-1)
#include<algorithm>
class Solution {
public:
    vector<int> set;
    vector<int> rank;
    inline void make_set(const int& n){
        set = vector<int>(n, ROOT);
        rank = vector<int>(n, 0);
    }
    int set_find(const int& a){
        if(set[a] == ROOT)return a;
        else return set[a] = set_find(set[a]);
    }
    void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b)return;

        if(rank[a] < rank[b]) set[a] = b;
        else if(rank[a] > rank[b]) set[b] = a;
        else{
            set[a] = b;
            rank[b]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //connected components / parent
        int n = s.size();
        make_set(n);
        for(const vector<int>& e: pairs)
            set_join(e[0], e[1]);
        
        //NOTE: smallest string with only 1 sort, instead of 2 sort
        vector<string> component(n);
        for(int i=0;i<n;i++)
            component[ set_find(i) ] += s[i];
        for(int i=0;i<n;i++)if(component[i].size() > 0)
            sort(component[i].begin(), component[i].end());

        vector<int> component_idx(n, 0);
        string ans = "";
        for(int i=0;i<n;i++){
            int root = set_find(i);
            ans += component[ root ][ component_idx[ root ]++ ];
        }
        return ans;
    }
};
