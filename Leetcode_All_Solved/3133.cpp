//constructive.
//just as what the hints say.

//the bitwise AND of all the elements is 0, since nums[0] = 0 merged with x. that is, just == x.

class Solution {
public:
    long long minEnd(int n, int x) {
        const int max_bits = 64;
        vector<long long> cnt_bits(max_bits, 0);
        for(long long b=0, bit=1;b<max_bits;b++, bit<<=1){
            cnt_bits[b] += ( (long long)(n-1) & bit ) != 0;
        }

        long long ans = x;
        int cnt_bits_b = 0;
        for(long long b=0, bit=1;b<max_bits;b++, bit<<=1){
            if( (x & bit) != 0 ) continue;

            ans += cnt_bits[cnt_bits_b++] * bit;
        }
        return ans;
    }
};
