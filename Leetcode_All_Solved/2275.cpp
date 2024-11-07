//O(n log max_nums) = O(nlog1e7)
#define max_bits 24
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt(max_bits, 0);
        for(const int& x: candidates){
            for(int b=0, bit=1;b<max_bits;b++, bit<<=1){
                cnt[b] += (x & bit) != 0;
            }
        }

        return *max_element(cnt.begin(), cnt.end());
    }
};
