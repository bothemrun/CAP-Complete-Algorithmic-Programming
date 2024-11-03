//m0
//[Thinking Process] --> knapsack + modular inverse

//[A] the order is irrelevant.
//1. since we want permutations.
//2. hence, doesn't have to stick with traversing index i.

//[B] knapsack dp

//[C] ensure distinctness:
//1. by traversing digit dp 
//2. that is, a decision tree where each level is a the taken count of a digit.

//[D] don't need char count in the dp state
//1. just multiply 1/count[char]! on the way.

//[E] denominator overflow --> modular inverse

//O(digit * cnt * sum * digit) = O(10^2 * 80/2 * 80/2*9) = O(10^3 * 80^2) = 1e3 * 64e2 = 6.4e6

class Solution {
public:
    const long long mod = (long long)1e9 + 7;

    vector<long long> fac;
    vector<long long> mod_inv;
    long long binary_exp(long long a, int b){
        if(b==0) return 1;

        long long res = binary_exp(a, b/2);
        res = (res*res)%mod;

        if(b%2==1) res = (res*a)%mod;

        return res;
    }

    inline void get_fac_mod_inv(int f){
        fac.resize(f+1);
        mod_inv.resize(f+1);

        fac[0] = 1;
        mod_inv[0] = 1;

        for(long long i=1;i<=f;i++){
            fac[i] = ( i * fac[i-1] )%mod;

            mod_inv[i] = binary_exp(fac[i], mod-2);
        }
    }

    int n;
    int all_sum = 0;

    const long long notyet = (-1);
    vector<vector<vector<long long>>> memo;
    long long knapsack_mod_inv(const vector<int>& digit2cnt, int digit, int cnt, int sum){
        if(digit>9){
            //even if n%2 == 1, cnt==n/2 is still ok.
            return cnt==n/2 && sum==all_sum/2;
        }

        //pruning
        if(sum > all_sum/2 || cnt > n/2) return 0;

        if(memo[digit][cnt][sum] != notyet) return memo[digit][cnt][sum];

        long long ret = 0;
        for(int even_cnt=0;even_cnt<=digit2cnt[digit];even_cnt++){
            int odd_cnt = digit2cnt[digit] - even_cnt;
            if(odd_cnt > n/2+1) continue;
            if(even_cnt > n/2) break;

            ret = (
                ret +
                ( mod_inv[even_cnt] * mod_inv[odd_cnt] )%mod * 
                knapsack_mod_inv(digit2cnt, digit+1, cnt + even_cnt, sum + digit * even_cnt) % mod
            )%mod;
        }
        return memo[digit][cnt][sum] = ret;
    }

    int countBalancedPermutations(string num) {
        n = num.size();
        get_fac_mod_inv(n/2 + 1);


        vector<int> digit2cnt(9+1, 0);
        for(const char& digit: num){
            digit2cnt[digit - '0']++;
            all_sum += digit - '0';
        }

        if(all_sum%2 == 1) return 0;

        memo.resize(9+1, vector<vector<long long>>(n/2+2, vector<long long>(all_sum/2 + 1, notyet) ) );
        long long ans = ( fac[n/2] * fac[n/2 + n%2] )%mod;
        return ( ans * knapsack_mod_inv(digit2cnt, 0, 0, 0) )%mod;
    }
};
