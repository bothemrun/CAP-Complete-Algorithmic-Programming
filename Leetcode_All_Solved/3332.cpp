//O(nk * n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> memo;
    const int notyet = (-1);
    int n, k;
    int enum_all(const vector<vector<int>>& stay, const vector<vector<int>>& travel, int day, int city){
        if(day<0){
            assert(day==(-1));
            return 0;
        }
        
        if(memo[day][city] != notyet) return memo[day][city];
        
        int ret = notyet;
        for(int next=0;next<n;next++){
            if(next==city){
                ret = max(
                    ret,
                    //stay[day][city] + enum_all(stay, travel, day-1, next)
                    stay[ (k-1) - day ][city] + enum_all(stay, travel, day-1, next)
                );
            }else{
                ret = max(
                    ret,
                    travel[city][next] + enum_all(stay, travel, day-1, next)
                );
            }
        }
        return memo[day][city] = ret;
    }
    
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        this->n = n;
        this->k = k;
        
        int ans = 0;
        memo.resize(k, vector<int>(n, notyet) );
        for(int city=0;city<n;city++){
            ans = max(
                ans,
                enum_all(stayScore, travelScore, k-1, city)
            );
        }
        return ans;
    }
};
