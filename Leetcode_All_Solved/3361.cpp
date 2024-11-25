static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        const int alphabet = 26;
        vector<vector<long long>> forward_cost(alphabet, vector<long long>(alphabet));
        vector<vector<long long>> backward_cost(alphabet, vector<long long>(alphabet));
        for(int a=0;a<alphabet;a++){
            for(int b=0;b<alphabet;b++){
                long long cost = 0;
                int cur = a;
                while(cur != b){
                    cost += nextCost[cur];
                    cur = (cur+1)%alphabet;//forward
                }
                forward_cost[a][b] = cost;
            }
        }
        
        for(int a=0;a<alphabet;a++){
            for(int b=0;b<alphabet;b++){
                long long cost = 0;
                int cur = a;
                while(cur != b){
                    cost += previousCost[cur];
                    cur = ( (cur-1)%alphabet + alphabet )%alphabet;
                }
                backward_cost[a][b] = cost;
            }
        }
        
        long long ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            ans += min( forward_cost[ s[i]-'a' ][ t[i]-'a' ], backward_cost[ s[i]-'a' ][ t[i]-'a' ] );
        }
        return ans;
    }
};
