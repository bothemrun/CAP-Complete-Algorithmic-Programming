//m1
//bitset by reading best time solution
#define max_bit ((int)2e5 + 1)
#include<bitset>
#include<assert.h>
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1 = 0, sum2 = 0;
        for(const int& c: aliceSizes) sum1 += c;

        bitset<max_bit> bs;
        for(const int& c: bobSizes){
            sum2 += c;
            bs[2*c] = 1;
        }

        for(const int& alice: aliceSizes){
            //sum1 != sum2
            //sum1 - alice + bob == sum2 - bob + alice
            //so 2bob = sum2 + 2alice - sum1
            int bob_target2 = sum2 + 2*alice - sum1;
            if(0<=bob_target2 && bob_target2<max_bit && bob_target2%2 == 0 && bs[bob_target2] )
                return vector<int>({alice, bob_target2/2});
        }

        assert(false);
        return vector<int>({-1, -1});
    }
};
