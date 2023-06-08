//NOTE: MLE for vector map
#define max_num ((int)1e9)
#include<algorithm>
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for(const int& x: nums) cnt[x]++;

        int match = 0;
        for(const int& x: nums)if(cnt[x] != 0){
            int y = k - x;
            
            if(x == y){
                match += cnt[x]/2;
                cnt[x] = cnt[x]%2;
            }else{
                int match1 = min(cnt[x], cnt[y]);
                match += match1;
                cnt[x] -= match1;
                cnt[y] -= match1;
            }
        }

        return match;
    }
};
