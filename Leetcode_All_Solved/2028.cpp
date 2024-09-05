//O(n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int target = mean * (m+n);

        int known = 0;
        for(const int& x: rolls) known += x;

        int deficit = target - known;
        if(deficit > 6*n || deficit < 1*n) return vector<int>({});

        vector<int> ans(n, 1);
        deficit -= n*1;
        for(int& x: ans){
            x += min(5, deficit);

            deficit -= min(5, deficit);
            if(deficit == 0) break;
        }

        assert(deficit == 0);
        return ans;
    }
};
