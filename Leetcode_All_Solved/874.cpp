//m0
//tree set of tuples
//O(k * commands.size * log obstacles.size)
#define tii tuple<int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<tii> se;
        for(const vector<int>& o: obstacles){
            se.insert(tii(o[0], o[1]));
        }

        int x=0, y=0;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int dir = 0;

        int max_d = 0;
        for(const int& c: commands){
            if(c==(-1)){
                dir = (dir + 1)%4;
            }else if(c==(-2)){
                dir = (dir - 1 + 4)%4;
            }else{
                for(int t=0;t<c;t++){
                    int a = x + dx[dir];
                    int b = y + dy[dir];

                    if(se.find(tii(a, b)) != se.end()){
                        break;
                    }

                    x = a;
                    y = b;
                    max_d = max(max_d, a*a + b*b);
                }
            }
        }
        return max_d;
    }
};
