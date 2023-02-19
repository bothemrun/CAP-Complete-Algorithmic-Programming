#define proof 0 // 1 0
#define test 0 //1 0
#define MOD ( ((int)1e9) + 7)
#define max_num 30
#define mask_square (-1)
#include<unordered_map>
#include<assert.h>
#include<utility>
class Solution {
public:
    vector<int> prime;
    vector<int> prime_mask;

    #if proof == 1
    int max_product = 30;
    vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    void subset_proof(int& proof_cnt, int i=0, int product=1){
        if(product > max_product)return;
        if(i == p.size()){
            proof_cnt++;
            return;
        }
    
        subset_proof(proof_cnt, i+1, product);
        subset_proof(proof_cnt, i+1, product * p[i]);
    }
    #endif

    inline void prime_sieve(const int& n){
        vector<bool> is_prime(n + 1, true);
        for(int i=2;i*i<=n;i++)if(is_prime[i] == true){
            //NOTE: i*(numbers >= i), so i <= sqrt(n)
            for(int j=(i+0);i*j<=n;j++){
                int x = i * j;
                is_prime[x] = false;
            }
        }

        int mask = 1;
        for(int i=2;i<=n;i++)if(is_prime[i] == true){
            prime.push_back(i);
            prime_mask.push_back(mask);
            mask <<= 1;
        }
    }

    long long factorize2mask(long long x){
        if(x == 1)return 0;//NOTE:

        long long mask = 0;
        for(int i=0;i<prime.size();i++){
            int cnt = 0;
            while(x % prime[i] == 0){
                //NOTE: 1%any == 1
                cnt++;
                x /= prime[i];
            }

            if(cnt == 1){
                mask |= prime_mask[i];
            }

            //NOTE:
            if(cnt >= 2)return mask_square;

            if(x <= 1){
                assert(x != 0);
                break;
            }
        }

        return mask;
    }

    void subset(const vector<pair<long long, long long>>& prime_mask_cnt, long long& cnt, int i=0, long long subset_mask=0, long long product=1){
        if(i == prime_mask_cnt.size()){
            cnt = (cnt + product)%MOD;

            #if test == 1
            cout << "final: subset_mask " << subset_mask << " product " << product << endl;
            #endif
            return;
        }

        subset(prime_mask_cnt, cnt, i+1, subset_mask, product);
        //NOTE: operator precedence "|" < "==" 
        if( (subset_mask & prime_mask_cnt[i].first) == 0)
            subset(prime_mask_cnt, cnt, i+1, 
                (subset_mask | prime_mask_cnt[i].first), 
                (product * prime_mask_cnt[i].second)%MOD 
            );
    }

    inline long long pow2mod(long long cnt){
        long long res = 1;
        for(int i=0;i<cnt;i++){
            res *= 2;
            if(res >= MOD) res %= MOD;
        }
        return res - 1;
    }

    int squareFreeSubsets(vector<int>& nums) {
        prime_sieve(max_num);

        #if proof == 1
        int cnt_proof = 0;
        subset_proof(cnt_proof);
        cout << "cnt_proof: " << cnt_proof << endl;
        #endif

        unordered_map<long long, long long> prime_mask2cnt;
        for(const int& x: nums){
            long long mask = factorize2mask((long long)x);
            #if test == 1
            printf("x %d mask %lld\n", x, mask);
            #endif

            //NOTE: mask = 0, for x == 1,
            if(mask == mask_square) continue;

            if(prime_mask2cnt.count(mask) == 0)
                prime_mask2cnt[mask] = 1;
            else prime_mask2cnt[mask]++;
        }
        vector<pair<long long, long long>> prime_mask_cnt;
        for(auto& [prime_mask, cnt]: prime_mask2cnt){
            //prime_mask_cnt.push_back( pair<long long, long long>(prime_mask, cnt) );
            //NOTE: for num == 1
            if(prime_mask == 0)
                prime_mask_cnt.push_back( pair<long long, long long>(
                    prime_mask, 
                    pow2mod(cnt)
                    //( ( (long long)1 << cnt ) - 1 )%MOD 
                ) );
            else prime_mask_cnt.push_back( pair<long long, long long>(prime_mask, cnt) );

            #if test == 1
            printf("prime_mask %lld cnt %lld real_cnt %lld\n", prime_mask_cnt.back().first, cnt, prime_mask_cnt.back().second );
            #endif
        }

        long long cnt = 0;
        subset(prime_mask_cnt, cnt);
        return cnt - 1;//NOTE: the empty subset
    }
};
