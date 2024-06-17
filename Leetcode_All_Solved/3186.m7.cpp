//m7

//1. optimization --> dp or greedy
//2. preprocessing sorting in O(nlogn)
//3. space optim from O(n) to O(1)

//4. use j's monotonicity
//4.a. we can also use a while loop from j=i downwards in O(2)
//4.b. but for a general problem of forbidding power[i]-1 ~ power[i]-k,
//4.c. this ensures O(n) instead of O(n*k).

//#define Memo3(i) (memo[i%3])
#define Memo3(i) (memo[ (i)%3 ])
#define Memo(i) ( (i>=0)? Memo3(i):0LL )

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> p2sum;
        for(const int& p: power) p2sum[p] += p;

        int n = p2sum.size();
        vector<long long> uni_p(n);
        int p_i = 0;
        for(const auto& [p, s]: p2sum){
            uni_p[p_i++] = p;
        }

        sort(uni_p.begin(), uni_p.end());

        //4. use j's monotonicity
        int j=0;

        vector<long long> memo(3);
        for(int i=0;i<n;i++){
            while(j<i && !( uni_p[j] >= uni_p[i]-2 ) ){
                j++;
            }

            //choose or skip
            Memo3(i) = max(
                Memo(i-1),
                p2sum[ uni_p[i] ] + Memo(j-1)
            );
        }

        return Memo(n-1);
    }
};
