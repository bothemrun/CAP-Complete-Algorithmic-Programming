//DP paradigm:

//[A] recursion with memo

//[B] list the states
//states = (prefix i, holding stock or not, cool down or not)

//[C] standard DP: choose or skip

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    const int notyet = (-1);
    vector<vector<vector<int>>> memo;

    int enum_states(const vector<int>& prices, int i, bool holding, bool cooldown){
        if(i==n) return 0;

        if(memo[i][holding][cooldown] != notyet) return memo[i][holding][cooldown];

        int ret = notyet;
        if(cooldown == true){
            assert(holding == false);
            ret = enum_states(prices, i+1, false, false);
        }else{
            //standard DP: choose or skip
            if(holding==true){
                ret = max(
                    enum_states(prices, i+1, true, false),
                    prices[i] + enum_states(prices, i+1, false, true) //sold, cool down
                );
            }else{
                ret = max(
                    enum_states(prices, i+1, false, false),
                    -prices[i] + enum_states(prices, i+1, true, false)
                );
            }
        }
        return memo[i][holding][cooldown] = ret;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memo.resize(n, vector<vector<int>>(2, vector<int>(2, notyet) ) );

        return enum_states(prices, 0, false, false);
    }
};
