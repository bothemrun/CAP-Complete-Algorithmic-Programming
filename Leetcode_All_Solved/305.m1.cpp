//m1
// (optim 1): easy way to count islands, using set_join()
//instead of unordered_set

// (optim 2): don't use an additional land matrix, which cost an additional O(mn)

//union by rank & path compression, amortized O(1)
//so O(mn + k)
//since m*n <= 10^4, so O(k)

#define IDX(i, j) (n*i + j)
#define ROOT (-1)
#define WATER (-3)

class Solution {
public:
    int m, n;
    vector<int> set;
    vector<int> rank;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int island = 0;

    inline void add_land(const int& i, const int& j){
        set[IDX(i, j)] = ROOT;
        //NOTE: count islands here
        island++;
    }

    inline void make_set(const int& size){
        set = vector<int>(size, WATER);
        rank = vector<int>(size, 0);
    }

    int set_find(const int& a){
        if(set[a] == ROOT)return a;
        return set[a] = set_find(set[a]);
    }

    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b)return;

        //NOTE: count islands here, successful set merge/join
        island--;

        if(rank[a] < rank[b]) set[a] = b;
        else if(rank[a] > rank[b]) set[b] = a;
        else{
            set[a] = b;
            rank[b]++;
        }
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        this->m = m;
        this->n = n;

        make_set(m*n);

        vector<int> answer(positions.size());
        for(int p=0;p<positions.size();p++){
            int i = positions[p][0];
            int j = positions[p][1];

            if(set[IDX(i, j)] != WATER){
                //NOTE: edge case, already land here
                answer[p] = island;
                continue;
            }
            add_land(i, j);

            for(int k=0;k<dx.size();k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(!(0<=x && x<m && 0<=y && y<n)) continue;
                if(set[IDX(x, y)] == WATER) continue;

                set_join( IDX(i, j), IDX(x, y) );
            }

            answer[p] = island;
        }

        return answer;
    }
};
