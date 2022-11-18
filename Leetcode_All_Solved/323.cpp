class Solution {
public:
    int set_find(const int& a, vector<int>& set){
        if(set[a] == (-1))return a;
        return (set[a] = set_find(set[a], set));
    }
    void set_join(int a, int b, vector<int>& set, int& set_cnt){
        a = set_find(a, set);
        b = set_find(b, set);
        if(a != b){
            set[a] = b;
            set_cnt--;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> set(n, (-1));
        int set_cnt = n;
        for(const vector<int>& edge:edges)
            set_join(edge[0], edge[1], set, set_cnt);
        return set_cnt;
    }
};
