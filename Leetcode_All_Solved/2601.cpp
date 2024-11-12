//1. prev < cur - p
//2. p < cur, making the results positive
//3. pick p as large as possible

//1 --> p < cur - prev --> so condition 2 is not needed.

//O(prime sieve + N log (count of primes < max_nums) )
//for prime sieve of n, O(nloglogn)

#define max_nums 1000

class Solution {
public:
    inline void prime_sieve(vector<int>& prime, const int n){
        vector<bool> is_prime(n+1, true);
        for(int p=2;p*p<=n;p++)if(is_prime[p]){
            for(int composite=p*p;composite<=n;composite += p){
                is_prime[composite] = false;
            }
        }

        for(int p=2;p<=n;p++)if(is_prime[p]){
            prime.push_back(p);
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime;
        prime.push_back(0);//for unchanged
        prime_sieve(prime, max_nums);

        int n = nums.size();
        for(int i=0;i<n;i++){
            const int bound = (i-1>=0)? (nums[i] - nums[i-1]):nums[i];
            int p_i = ( lower_bound(prime.begin(), prime.end(), bound) - prime.begin() ) - 1;
            if(p_i < 0) return false;

            nums[i] -= prime[p_i];
        }

        return true;
    }
};
