//O(mn * (mn)!) = O(6 * 6!)

#define IDX(i, j) (i*n + j)
#define PSI pair<string, int>

#include<queue>
#include<algorithm>
#include<utility>
#include<unordered_set>

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size();
        int n = board.back().size();
        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, 1, 0, -1};

        string target = "123450";

        int start0idx;
        string start = "";
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                start += to_string(board[i][j]);

                if(board[i][j] == 0)
                    start0idx = IDX(i, j);
            }

        queue< PSI > q;
        unordered_set<string> inq;

        q.push( PSI(start, start0idx) );
        inq.insert(start);

        int level = 0;
        while(q.size()){
            int lsize = q.size();
            for(int l=0;l<lsize;l++){
                auto [u, u0idx] = q.front();
                q.pop();

                int i = u0idx/n;
                int j = u0idx%n;

                if(u == target) return level;

                for(int k=0;k<di.size();k++){
                    int x = i + di[k];
                    int y = j + dj[k];
                    if(!(0<=x && x<m && 0<=y && y<n)) continue;

                    string v = u;
                    swap( v[ u0idx ], v[ IDX(x, y) ] );

                    //excludes swapping 0 with itself
                    if(inq.count(v) != 0) continue;

                    q.push( PSI(v, IDX(x, y) ) );
                    inq.insert(v);
                }
            }

            level++;
        }

        return (-1);
    }
};
