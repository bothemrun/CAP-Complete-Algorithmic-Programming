//m2
//m0 is precious, and m1 takes ideas and intuition form m0.
//m2 optim is dedup.
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp_ugly(n);
        dp_ugly[0] = 1;
        int i1 = 0, i2 = 0, i3 = 0;

        //NOTE: optim: so don't have to multiply every time
        int heap_min1 = 2, heap_min2 = 3, heap_min3 = 5;
        
        for(int i=1;i<n;i++){
            dp_ugly[i] = min(heap_min1, min(heap_min2, heap_min3) );

            //NOTE: dedup
            if(dp_ugly[i] == heap_min1)
                heap_min1 = 2 * dp_ugly[++i1];
            if(dp_ugly[i] == heap_min2)
                heap_min2 = 3 * dp_ugly[++i2];
            if(dp_ugly[i] == heap_min3)
                heap_min3 = 5 * dp_ugly[++i3];
        }
        return dp_ugly[n-1];
    }
};
