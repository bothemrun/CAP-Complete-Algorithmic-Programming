#define t3i tuple<int,int,int>
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();//diff def
        int n = moveTime.back().size();
        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, 1, 0, -1};
        auto cmp = [](const t3i& a, const t3i& b){
            const auto& [ta, ia, ja] = a;
            const auto& [tb, ib, jb] = b;
            return ta > tb;//minheap
        };
        priority_queue<t3i, vector<t3i>, decltype(cmp)> minheap(cmp);
        minheap.push(t3i(0, 0, 0));
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        while(true){
            auto [time, i, j] = minheap.top();
            minheap.pop();
            
            if(i==m-1 && j==n-1) return time;
            
            for(int k=0;k<di.size();k++){
                int x = i+di[k];
                int y = j+dj[k];
                if(!(0<=x && x<m && 0<=y && y<n)) continue;
                
                if(dist[x][y] > 1 + max(time, moveTime[x][y]) ){
                    dist[x][y] = 1 + max(time, moveTime[x][y]);
                    minheap.push( t3i(dist[x][y], x, y) );
                }
            }
        }
    }
};
