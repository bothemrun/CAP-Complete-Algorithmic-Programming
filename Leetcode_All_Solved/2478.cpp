//m0
//Thinking Process:

//[A] wisdompeak Interval I: Partition

//1. dp[i][p] for prefix [0, i] with (p+1) parts, and enumerate last part's front.
//2. but O(n*k*n) = O(1e9) TLE


//[B] use a special status value
//1. end_at --> so we only have to enumerate i-1
//2. O(n*k)

//optim: cache locality
//900 ms vs. 70 ms
#define cache_locality 1 //0: dp[n][k][2], 1: dp[n][2][k]

class Solution {
public:
    const int mod = (int)1e9 + 7;
    vector<vector<vector<int>>> memo;
    const int notyet = INT_MIN;

    int min_len;

    inline bool is_prime(const char& c){
        return c=='2' || c=='3' || c=='5' || c=='7';
    }

    int enum_partition_end(const string& s, int i, int part, bool end){
        //pruing
        if(i < part) return 0;

        if(part == (-1)) return i==(-1);


        assert(i>=0 && part>=0);

#if cache_locality == 1
        if(memo[i][end][part] != notyet) return memo[i][end][part];
#else
        if(memo[i][part][end] != notyet) return memo[i][part][end];
#endif

        bool is_p = is_prime(s[i]);

        if(end == true){
            //at least minLength

#if cache_locality == 1
            return memo[i][end][part] = 
                (is_p==true)?
                0:
                enum_partition_end(s, i - (min_len-1), part, false);
#else
            return memo[i][part][end] = 
                (is_p==true)?
                0:
                enum_partition_end(s, i - (min_len-1), part, false);
#endif
        }

        //1. continue, skip this cut
        int ret = enum_partition_end(s, i-1, part, false);

        //2. choose this cut
        if(is_p==true){
            ret = (
                ret +
                enum_partition_end(s, i-1, part-1, true)
            )%mod;
        }

#if cache_locality == 1
        return memo[i][end][part] = ret;
#else
        return memo[i][part][end] = ret;
#endif
    }

    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        this->min_len = minLength;

#if cache_locality == 1
        memo.resize(n, vector<vector<int>>(2, vector<int>(k, notyet) ) );
#else
        memo.resize(n, vector<vector<int>>(k, vector<int>(2, notyet) ) );
#endif

        return enum_partition_end(s, n-1, k-1, true);
    }
};
