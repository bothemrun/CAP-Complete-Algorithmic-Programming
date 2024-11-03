static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#define t4i tuple<int,int,int,bool>
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();//diff def
        int n = moveTime.back().size();
        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, 1, 0, -1};
        auto cmp = [](const t4i& a, const t4i& b){
            const auto& [ta, ia, ja, turna] = a;
            const auto& [tb, ib, jb, turnb] = b;
            return ta > tb;//minheap
        };
        priority_queue<t4i, vector<t4i>, decltype(cmp)> minheap(cmp);
        minheap.push(t4i(0, 0, 0, false));
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        while(true){
            auto [time, i, j, turn] = minheap.top();
            minheap.pop();
            
            if(i==m-1 && j==n-1) return time;
            
            for(int k=0;k<di.size();k++){
                int x = i+di[k];
                int y = j+dj[k];
                if(!(0<=x && x<m && 0<=y && y<n)) continue;
                
                int step = (turn==false)? 1:2;
                if(dist[x][y] > step + max(time, moveTime[x][y]) ){
                    dist[x][y] = step + max(time, moveTime[x][y]);
                    minheap.push( t4i(dist[x][y], x, y, !turn) );
                }
            }
        }
    }
};
