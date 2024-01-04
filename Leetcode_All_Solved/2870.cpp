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
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(const int& x: nums) cnt[x]++;

        int op = 0;
        for(const auto& [k, v]: cnt){
            if(v==1) return (-1);

            if(v==2 || v==3) op++;
            else if(v==4) op += 2;
            else if(v%3==0) op += v/3;
            else op += v/3 + 1;
        }
        return op;
    }
};
