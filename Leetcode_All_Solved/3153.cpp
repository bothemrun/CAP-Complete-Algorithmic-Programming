//O(n)
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();

        int digit_size = 0;
        int x0 = nums.front();
        while(x0 != 0){
            digit_size++;
            x0 /= 10;
        }

        vector<vector<long long>> digit2cnt(digit_size, vector<long long>(10, 0));

        for(int x: nums){
            for(int i=0;i<digit_size;i++){
                digit2cnt[i][ x%10 ]++;

                x /= 10;
            }
        }

        long long ans = 0;
        for(int i=0;i<digit_size;i++){
            long long sum = 0;
            for(long long cnt: digit2cnt[i]){
                ans += sum * cnt;

                sum += cnt;
            }
        }

        return ans;
    }
};
