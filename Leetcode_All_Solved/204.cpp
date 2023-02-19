class Solution {
public:
    inline int prime_sieve(int n){
        vector<bool> is_prime(n+1, true);
        for(int i=2;i*i<=n;i++)if(is_prime[i] == true){
            //NOTE: i*(numbers >= i), so i <= sqrt(n)
            for(int j=(i+0);i*j<=n;j++){
                int x = i*j;
                is_prime[x] = false;
            }
        }

        int cnt = 0;
        for(int i=2;i<=n;i++)if(is_prime[i] == true)
            cnt++;
        return cnt;
    }
    int countPrimes(int n) {
        return prime_sieve(n - 1);
    }
};
