//m1
#include<algorithm>
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int p = primes.size();
        vector<long long> dp_ugly(n);
        dp_ugly[0] = 1;

        vector<int> prime_ugly_idx(p, 0);
        vector<long long> multi(primes.begin(), primes.end());

        for(int i=1;i<n;i++){
            long long ugly = *min_element(multi.begin(), multi.end());
            dp_ugly[i] = ugly;

            for(int j=0;j<p;j++){
                if(ugly == multi[j])
                    multi[j] = primes[j] * dp_ugly[ ++prime_ugly_idx[j] ];
            }
        }

        return dp_ugly[n-1];
    }
};
