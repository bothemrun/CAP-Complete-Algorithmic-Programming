//like the prime sieve algorithm, limit the cofactor process to NlogN
//sum of (1/1+1/2+1/3...) which is actually the harmonic series.

#define ROOT (-1)

class Solution {
public:
    vector<int> dsu;
    vector<int> rank;
    inline void make_set(int size){
        dsu.resize(size, ROOT);
        rank.resize(size, 1);
    }
    int set_find(const int& a){
        if(dsu[a] == ROOT) return a;
        return dsu[a] = set_find(dsu[a]);
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a==b) return;

        if(rank[a] < rank[b]) dsu[a] = b;
        else if(rank[a] > rank[b]) dsu[b] = a;
        else{
            dsu[a] = b;
            rank[b]++;
        }
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        make_set(n + 1);
        for(int divisor=threshold+1;divisor<=n;divisor++)
            for(int j=divisor*2;j<=n;j += divisor) set_join(divisor, j);
        

        vector<bool> ans;
        for(const vector<int>& q: queries)
            ans.push_back( set_find(q[0]) == set_find(q[1]) );
        return ans;
    }
};
