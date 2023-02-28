//union by rank & path compression in amortized O(1)
//O(k), k := edges.size()
#define ROOT (-1)
class Solution {
public:
    vector<int> set;
    vector<int> rank;
    vector<int> cnt;
    inline void make_set(const int& size){
        set = vector<int>(size, ROOT);
        rank = vector<int>(size, 0);
        cnt = vector<int>(size, 1);
    }

    int set_find(const int& a){
        if(set[a] == ROOT) return a;
        return set[a] = set_find(set[a]);
    }

    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b)return;

        if(rank[a] < rank[b]){
            set[a] = b;
            cnt[b] += cnt[a];
        }else if(rank[a] > rank[b]){
            set[b] = a;
            cnt[a] += cnt[b];
        }else{
            set[a] = b;
            cnt[b] += cnt[a];
            rank[b]++;
        }
    }

    inline void set_count(vector<int>& setcnt){
        for(int i=0;i<set.size();i++)if(set[i] == ROOT) setcnt.push_back(cnt[i]);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        make_set(n);
        for(const vector<int>& e: edges)
            set_join(e[0], e[1]);
        
        vector<int> setcnt;
        set_count(setcnt);

        long long cntpair = 0;
        long long sum_tmp = 0;
        for(int i=setcnt.size()-1;i>=0;i--){
            cntpair += sum_tmp * setcnt[i];
            sum_tmp += setcnt[i];
        }
        return cntpair;
    }
};
