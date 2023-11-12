//m1
//Actually m0 is much better, although m1 is faster with the same complexity.

//Thinking Process

//[A] Proof Existence
//1. WLOG, we want all to be 1 (0 also works).
//2. we apply the prefix operations from i=n-1 to 0
//3. for the operation at i, we only invert only if s[i] is 0.
//4. finally at i=0, this is the base case.
//4. by induction, we proved its existence.


//[B] inversion operations are independent
//1. so we can separate these 2 types of prefix & suffix operations.

//[C] enum breakpoints
//1. first we build prefix & suffix dp in O(n).
//2. then enum breakpoints like prefix_dp[i] + suffix_dp[i+1]

//O(n)



//[D] The Above Better, But Here's A Faster Bad Method:
//1. The notes above are from method 0.
//which is actually better.

//1. by [B], we can re-arrange a series of operations with increasing i,
//2. such that the left prefix part of the array has the same values.
//3. after for loop at i:
//4. [0, i] all have the same values.
//5. s[i] & s[i+1] have the same number of inversion operations.
//6. now compare s[i] & s[i+1].
//7. if they're not the same, then now it's the only time to invert their relationship.

//[E]. in summary for the above, 
//1. by [B], we can re-arrange the operations with increasing i.
//2. use a for loop, and the left prefix part has the same values.
//3. s[i] & s[i+1] has the same number of inversions currently.

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();

        long long ans = 0;
        for(long long i=0;i+1<n;i++){
            if(s[i] != s[i+1])
                ans += min(i+1, (n-1) - i );
        }

        return ans;
    }
};
