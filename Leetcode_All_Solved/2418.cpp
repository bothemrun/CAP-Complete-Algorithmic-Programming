#include<functional>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();

        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[i] = i;

        function<bool(const int&, const int&)> cmp = [&heights](const int& a, const int& b){
            return heights[a] > heights[b];
        };
        sort(idx.begin(), idx.end(), cmp);

        vector<string> ans(n);
        for(int i=0;i<n;i++) ans[i] = names[ idx[i] ];
        return ans;
    }
};
