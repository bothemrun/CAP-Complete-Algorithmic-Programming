//1. overflow in denominators --> modular inverse 
//2. by Fermat's little theorem, a^(p-1) == 1 (mod p)
//3. and binary exponentiation

//O(n * log p) = O(1e5 * log1e9) = O(1e5 * 30)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const long long mod = (long long)1e9 + 7;
    long long binary_exp(long long a, int b){
        if(b==0) return 1;

        long long res = binary_exp(a, b/2);
        res = (res*res)%mod;

        if(b%2==1) res = (res*a)%mod;

        return res;
    }
    int countAnagrams(string s) {
        int n = s.size();

        vector<long long> fac(n + 1);
        vector<long long> mod_inv(n + 1);
        fac[0] = 1;
        mod_inv[0] = 1;
        for(long long i=1;i<=n;i++){
            fac[i] = (i * fac[i-1])%mod;

            mod_inv[i] = binary_exp(fac[i], mod-2);
        }

        long long ans = 1;
        int i=0;
        while(i<n){
            int j=i;
            while(j+1<n && s[j+1] != ' '){
                j++;
            }

            vector<int> char2cnt(26, 0);
            for(int k=i;k<=j;k++) char2cnt[ s[k]-'a' ]++;

            ans = ( ans * fac[ j - (i-1) ] )%mod;
            for(int c=0;c<26;c++){
                ans = ( ans * mod_inv[ char2cnt[c] ] )%mod;
            }

            //update
            i = j+2;//skip the single space
        }
        return ans;
    }
};
