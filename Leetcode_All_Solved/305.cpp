//union by rank & path compression, amortized O(1)
//so O(mn + k)
//since m*n <= 10^4, so O(k)
#define IDX(i, j) (n*i + j)
#include<unordered_set>
class Solution {
public:
    int m, n;
    vector<int> set;
    vector<int> rank;
    
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    inline void make_set(const int& size){
        set = vector<int>(size, (-1));
        rank = vector<int>(size, 0);
    }

    int set_find(const int& a){
        if(set[a] == (-1)) return a;
        return set[a] = set_find(set[a]);
    }

    inline void set_join(int a, int b){
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

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        this->m = m;
        this->n = n;
        vector<vector<bool>> land(m, vector<bool>(n, false));
        make_set(m*n);

        vector<int> answer(positions.size());
        int island = 0;
        for(int p=0;p<positions.size();p++){
            int i = positions[p][0];
            int j = positions[p][1];

            if(land[i][j] == true){
                //edge case, already land
                answer[p] = island;
                continue;
            }
            land[i][j] = true;

            unordered_set<int> root_set;
            for(int k=0;k<dx.size();k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(!(0<=x && x<m && 0<=y && y<n)) continue;
                if(land[x][y] == false) continue;
                
                root_set.insert( set_find( IDX(x, y) ) );
                //NOTE: can't join sets while checking original roots, 
                //NOTE: since the roots change when set_join()
                //set_join( IDX(i, j), IDX(x, y) );
            }

            //NOTE: join sets afterwards
            for(const int& root: root_set)
                set_join(root, IDX(i, j) );

            island -= root_set.size() - 1;
            answer[p] = island;
        }

        return answer;
    }
};
