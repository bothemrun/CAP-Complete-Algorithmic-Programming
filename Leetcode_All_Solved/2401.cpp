//m0
//O(32n)
#define max_bit 32

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
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int ans = 1;
        //window [i, j]
        int j = (-1);

        vector<int> bits_cnt(max_bit, 0);
        int bits_or = 0;

        for(int i=0;i<n;i++){
            //update, add
            while(j+1<n && (bits_or & nums[j+1]) == 0){
                j++;
                bits_or |= nums[j];

                for(int b=0, bit=1;b<max_bit;b++, bit <<= 1){
                    bits_cnt[b] += ( nums[j] & bit ) != 0;
                }
            }

            assert(i<=j);
            ans = max(ans, j - (i-1));

            //update, drop
            for(int b=0, bit=1;b<max_bit;b++, bit <<= 1){
                if( ( nums[i] & bit ) != 0 ){
                    if(--bits_cnt[b] == 0){
                        bits_or ^= bit;
                    }

                    assert( bits_cnt[b] >= 0 );
                }
            }
        }

        return ans;
    }
};
