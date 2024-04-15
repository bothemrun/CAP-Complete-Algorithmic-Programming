//optim: static function variable in 279 Perfect Squares	medium
#define max_nums (100+1)

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline void prime_sieve(vector<bool>& prime, int n){
        for(int p=2;p*p<=n;p++)if(prime[p]){
            for(int comp=p*p;comp<=n;comp += p) prime[comp] = false;
        }

        prime[1] = false;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        static bool done = false;
        static vector<bool> prime(max_nums, true);

        if(done == false){
            done = true;
            prime_sieve(prime, max_nums-1);
        }


        int n = nums.size();
        
        int first;
        for(first=0;first<n;first++)if(prime[ nums[first] ]) break;

        int last;
        for(last=n-1;last>=0;last--)if(prime[ nums[last] ]) break;

        return last - first;
    }
};
