#include<limits.h>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
//#include<math.h>
class Solution {
public:
    void factorize(const long long& n, unordered_map<long long, vector<long long>>& dp_prime){
        if(dp_prime.count(n) != 0)return;
        
        dp_prime[n] = vector<long long>();
        //long long x = n;
        //for(long long i=2;i<=sqrt(n);i++)if(n % i == 0){
        for(long long i=2;i<=n;i++)if(n % i == 0){
            factorize(n/i, dp_prime);
            dp_prime[n] = dp_prime[n/i];
            dp_prime[n].push_back(i);
            
            /*cout << "primes for " << n << endl<<":";
            for(int p: dp_prime[n]) cout << p << " ";
            cout << endl;*/
            
            break;
        }
    }
    int smallestValue(int n) {
        unordered_set<long long> dedup;
        unordered_map<long long, vector<long long>> dp_prime;
        long long min_n = n;
        long long lln = n;
        while(lln >= 2 && dedup.count(lln) == 0 ){
            factorize(lln, dp_prime);
            
            //new n
            //cout << lln <<endl;
            long long new_n = 0;
            for(const long long& p: dp_prime[lln]){
                new_n += p;
            }
            
            //update
            dedup.insert(lln);
            lln = new_n;
            min_n = min(min_n, new_n);
        }
        return min_n;
    }
};
