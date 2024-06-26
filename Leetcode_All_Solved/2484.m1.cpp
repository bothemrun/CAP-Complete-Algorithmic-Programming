//m1

//[A] the thinking process from m0 is important.


//[B] all states from m0, can we improve it?

//1. if we have chosen first 3 chars, 

//2. then dp(i, first, second, 3) = count of length 2 subsequences "first second" in i's suffix

//3. cut to O(n * 10^2 * 3), but the prefix / suffix array is the intuition for m2.


//[C] prefix(i, a, b)

//1. dp method over prefix sum method here.
//2. O(n * 10^2)


//[D] totally O(n * 10^2 * 3)

#define mod ((int)1e9 + 7)
#define alphabet (10)
#define no_char (alphabet)
#define palin_len 3

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const int notyet = (-1);

    vector<vector<int>> prefix_cnt;
    vector<vector<vector<int>>> prefix;

    vector<vector<vector<vector<int>>>> memo;

    int prefix2subse(const string& s, int i, int a, int b){
        if(i-1<0) return 0;

        if(prefix[i][a][b] != notyet) return prefix[i][a][b];

        int ret = prefix2subse(s, i-1, a, b);

        if(s[i]-'0' == b){
            ret = (
                ret +
                prefix_cnt[i-1][a]
            )%mod;
        }

        return prefix[i][a][b] = ret;
    }

    int enum_states(const string& s, int i, int first, int second, int len){

        //finished 1.
        //this before if(i<0)
        if(len==palin_len){
            return prefix2subse(s, i, first, second);
        }

        //still not finished 1.
        if(i<0) return 0;

        if(memo[i][first][second][len] != notyet) return memo[i][first][second][len];

        //2. choose to lengths 1~3
        int choose = 0;
        if(len==0){
            choose = enum_states(s, i-1, s[i]-'0', no_char, 1);
        }else if(len==1){
            choose = enum_states(s, i-1, first, s[i]-'0', 2);
        }else if(len==2){
            //the middle char
            choose = enum_states(s, i-1, first, second, 3);
            //still have choose + skip !!!
        }

        //1. skip
        int skip = enum_states(s, i-1, first, second, len);

        return memo[i][first][second][len] = (skip + choose)%mod;        
    }

    int countPalindromes(string s) {
        int n = s.size();

        prefix_cnt.resize(n, vector<int>(alphabet));
        prefix_cnt[0].resize(alphabet, 0);
        prefix_cnt[0][ s[0]-'0' ]++;

        for(int i=1;i<n;i++){
            prefix_cnt[i] = prefix_cnt[i-1];

            prefix_cnt[i][ s[i]-'0' ]++;
        }

        prefix.resize(n, vector<vector<int>>(alphabet, vector<int>(alphabet, notyet) ) );

        memo.resize(n, vector<vector<vector<int>>>(alphabet + 1, vector<vector<int>>(alphabet + 1, vector<int>(palin_len, notyet) ) ) );

        return enum_states(s, n-1, no_char, no_char, 0);
    }
};
