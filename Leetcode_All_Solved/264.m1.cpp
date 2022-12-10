//m1
//NOTE: optim from m0, but not really pushing into min heap, just use indices
//NOTE: m0 is precious, it's where the intuition and ideas come from for m1.
#include<algorithm>
#include<unordered_set>
class Solution {
public:
    inline int dedup(int& i_prime, const int& prime, vector<int>& dp_ugly, unordered_set<int>& s){
        while( s.count(dp_ugly[i_prime] * prime) != 0 ) i_prime++;
        return dp_ugly[i_prime] * prime;
    }
    int nthUglyNumber(int n) {
        vector<int> dp_ugly(n);
        dp_ugly[0] = 1;
        
        unordered_set<int> s;
        s.insert(1);
        //NOTE: indices to replace pushing heaps
        int i1 = 0, i2 = 0, i3 = 0;
        for(int i=1;i<n;i++){
            int heap_min1 = dedup(i1, 2, dp_ugly, s);
            int heap_min2 = dedup(i2, 3, dp_ugly, s);
            int heap_min3 = dedup(i3, 5, dp_ugly, s);

            dp_ugly[i] = min(heap_min1, min(heap_min2, heap_min3) );
            s.insert(dp_ugly[i]);
            
            if(dp_ugly[i] == heap_min1) i1++;
            else if(dp_ugly[i] == heap_min2) i2++;
            else i3++;
            cout << dp_ugly[i] << endl;
        }
        return dp_ugly[n-1];
    }
};
