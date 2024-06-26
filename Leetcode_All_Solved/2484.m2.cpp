//m2

//[A] the thinking process from m0 & m1 is important.


//[B] further reduce by the prefix(i, a, b) by prefix & suffix

//1. just loop over i as the middle char, and use prefix & suffix.



//[C] prefix(i, a, b)

//1. dp method over prefix sum method here.
//2. O(n * 10^2)


//[D] complexity O(n * 10^2)

#define mod ((long long)1e9 + 7LL)
#define alphabet (10)

#define c2i(c) (c-'0')

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const long long notyet = (-1);
    int n;

    vector<vector<long long>> pre_cnt;
    vector<vector<vector<long long>>> pre;

    vector<vector<long long>> suf_cnt;
    vector<vector<vector<long long>>> suf;

    long long pre2subse(const string& s, int i, int a, int b){
        if(i-1<0) return 0;

        if(pre[i][a][b] != notyet) return pre[i][a][b];

        long long ret = pre2subse(s, i-1, a, b);

        if(c2i(s[i]) == b){
            ret = (
                ret +
                pre_cnt[i-1][a]
            )%mod;
        }

        return pre[i][a][b] = ret;
    }

    long long suf2subse(const string& s, int i, int a, int b){
        if(i+1>=n) return 0;

        if(suf[i][a][b] != notyet) return suf[i][a][b];

        long long ret = suf2subse(s, i+1, a, b);

        if(c2i(s[i]) == a){
            ret = (
                ret +
                suf_cnt[i+1][b]
            )%mod;
        }

        return suf[i][a][b] = ret;
    }

    int countPalindromes(string s) {
        this->n = s.size();

        //1. prefix
        pre_cnt.resize(n, vector<long long>(alphabet) );
        pre_cnt.front().resize(alphabet, 0);
        pre_cnt.front()[ c2i(s.front()) ] = 1;

        for(int i=1;i<n;i++){
            pre_cnt[i] = pre_cnt[i-1];

            pre_cnt[i][ c2i(s[i]) ]++;
        }

        pre.resize(n, vector<vector<long long>>(alphabet, vector<long long>(alphabet, notyet) ) );

        //2. suffix
        suf_cnt.resize(n, vector<long long>(alphabet) );
        suf_cnt.back().resize(alphabet, 0);
        suf_cnt.back()[ c2i(s.back()) ] = 1;

        for(int i=n-2;i>=0;i--){
            suf_cnt[i] = suf_cnt[i+1];

            suf_cnt[i][ c2i(s[i]) ]++;
        }

        suf.resize(n, vector<vector<long long>>(alphabet, vector<long long>(alphabet, notyet) ) );

        //3. enum middle char
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(int a=0;a<alphabet;a++){
                for(int b=0;b<alphabet;b++){
                    ans = (
                        ans +
                        pre2subse(s, i-1, a, b) *
                        suf2subse(s, i+1, b, a)
                    )%mod;
                }
            }
        }
        return ans;
    }
};
