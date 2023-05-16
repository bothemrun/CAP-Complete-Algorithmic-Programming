#include<assert.h>
#include<algorithm>
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        long long sum1 = 0, sum2 = 0;
        for(const int& c: aliceSizes) sum1 += c;
        for(const int& c: bobSizes) sum2 += c;
        
        sort(bobSizes.begin(), bobSizes.end());
        for(const int& alice: aliceSizes){
            //sum1 != sum2 -->
            //sum1 - alice + bob == sum2 - bob + alice
            //so bob = ( sum2 + 2alice - sum1 )/2
            if( (sum2 + 2*alice - sum1)%2 != 0 ) continue;
            int bob_target = (sum2 + 2*alice - sum1)/2;
            int low = lower_bound(bobSizes.begin(), bobSizes.end(), bob_target) - bobSizes.begin();
            if(low < bobSizes.size() && bobSizes[low] == bob_target)
                return vector<int>({alice, bob_target});
        }

        assert(false);
        return vector<int>({-1, -1});
    }
};
