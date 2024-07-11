//m0

//[A] brute force

//1. prefix & suffix product + gcd(a,b) in log(min(a, b)).
//overflow for the products


//[B] observe: what make the split invalid?

//1. some common factor across the 2 splits
//2. --> say f across [a, b] (not filled)
//3. --> on/off interval problem --> line sweep / diff array.


//[C] factorization by primes

//1. primes by prime sieve

//2. for x, at most 1 prime factor > sqrt(x).
//2.a. otherwise, p1*p2 > sqrt(x) * sqrt(x) > x. contradict.

//3. so only prime sieve up to sqrt(max_nums)

//4. https://cp-algorithms.com/algebra/factorization.html
//4.a. x /= p^any
//4.b. break if p*p > x
//4.c. finally, if x != 1 --> the only prime factor > sqrt(x)


//O(n * sqrt(max_nums)) = O(1e4 * 1e3) = O(1e7)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline void prime_sieve(const int n, vector<int>& primes){
        vector<bool> is_prime(n+1, true);
        for(int p=2;p*p <= n;p++)if(is_prime[p] == true){
            //p*p p(p+1), p(p+2), p(p+3),... until <= n, are not primes.
            //why not use p*2, p*3,...? 'cuz p*2 already done by the smaller q=2 by q*p
            for(int x=p*p;x<=n;x += p){
                is_prime[x] = false;
            }
        }


        for(int p=2;p<=n;p++)if(is_prime[p]){
            primes.push_back(p);
        }
    }

    inline void prime_factorization(const vector<int>& primes, int x, vector<int>& p_factor){
        for(const int& p: primes){
            if(p*p > x) break;

            if(x%p == 0){
                p_factor.push_back(p);

                while(x%p == 0){
                    x /= p;
                }
            }
        }

        if(x != 1){
            p_factor.push_back(x);
        }
    }

    int findValidSplit(vector<int>& nums) {
        vector<int> primes;
        prime_sieve( *max_element(nums.begin(), nums.end()) , primes);

        int pn = primes.size();
        unordered_map<int,int> p2i;
        for(int pi=0;pi<pn;pi++){
            p2i[ primes[pi] ] = pi;
        }

        vector<int> idx2start(pn, INT_MAX);
        vector<int> idx2end(pn, INT_MIN);

        //O(n * size of primes) = O(n * sqrt(max_nums))
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];

            vector<int> p_factor;
            prime_factorization(primes, nums[i], p_factor);


            for(const int& f: p_factor){
                const int pi = p2i[f];

                idx2start[pi] = min(idx2start[pi], i); //although only changed once
                idx2end[pi] = max(idx2end[pi], i);
            }
        }


        vector<int> diff(n, 0);
        for(int pi=0;pi<pn;pi++)if(idx2start[pi] != INT_MAX){
            //ok for the same positions
            diff[idx2start[pi]]++;
            //not end+1
            diff[idx2end[pi]]--;
        }

        int sweep = 0;
        for(int i=0;i+1<n;i++){
            sweep += diff[i];

            if(sweep == 0) return i;
        }
        return (-1);
    }
};
