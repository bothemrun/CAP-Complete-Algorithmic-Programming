//O(n * max digits of k) = O(n*10)
//DP Interval II

//go from i=0 forwards for easily compute the substring's value.
#define mod ((int)1e9 + 7)

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
    const int impossible = INT_MAX;
    vector<int> memo;
    int k;

    int partition(const string& s, int i){
        if(i==n) return 1;
        if(s[i] == '0') return impossible;

        if(memo[i] != notyet) return memo[i];

        int ret = 0;
        long long sum = 0;
        for(int j=i;j<n;j++){
            sum = sum*10LL + (s[j] - '0');
            if(!(sum<=k)) break;

            int sub = partition(s, j+1);
            if(sub == impossible) continue;

            ret = (ret + sub)%mod;//no overflow
        }
        return memo[i] = ret;
    }

    int numberOfArrays(string s, int k) {
        this->n = s.size();
        this->k = k;
        memo.resize(n, notyet);

        return partition(s, 0);
    }
};
