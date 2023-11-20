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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        unordered_map<char, int> last_idx;
        int ans = 0;//no overflow

        for(int i=0;i<n;i++){
            const string& gar = garbage[i];

            ans += gar.size();
            for(const char& g: gar){
                last_idx[g] = i;
            }
        }

        for(const auto& [g, idx]: last_idx){
            //if no key, then no.
            for(int i=0;i<idx;i++)
                ans += travel[i];
        }

        return ans;
    }
};
