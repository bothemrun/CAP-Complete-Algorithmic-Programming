//O(nlogn) due to sorting
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
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> num2cnt;
        for(const int& x: arr) num2cnt[x]++;

        vector<int> cnt;
        for(const auto& [key, val]: num2cnt)
            cnt.push_back(val);
        
        sort(cnt.begin(), cnt.end());
        int n = cnt.size();
        int i=0;
        while(k > 0 && i<n){
            k -= cnt[i];
            if(k >= 0) i++;
        }
        return n - i;
    }
};
