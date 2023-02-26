//m1
//from O(nlogn) to O(n)
//path compression + union by rank
class Solution {
public:
    vector<int> set;
    vector<int> rank;
    inline void make_set(const int& n){
        set = vector<int>(n, -1);
        rank = vector<int>(n, 0);
    }
    int set_find(const int& a){
        if(set[a] == -1)return a;
        return set[a] = set_find(set[a]);
    }
    bool set_join_same_set(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b)return true;

        if(rank[a] < rank[b]) set[a] = b;
        else if(rank[a] > rank[b]) set[b] = a;
        else{
            set[a] = b;
            rank[b]++;
        }
        return false;
    }
    inline int set_count(){
        int cnt = 0;
        for(const int& a: set)if(a == -1)cnt++;
        return cnt;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        make_set(n);
        int redundant = 0;
        for(const vector<int>& e: connections){
            if( set_join_same_set(e[0], e[1]) == true ) redundant++;
        }

        int need = set_count() - 1;
        if(need > redundant) return (-1);
        return need;
    }
};
