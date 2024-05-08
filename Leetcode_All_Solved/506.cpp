#include<functional>
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
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[i] = i;

        function<bool(const int&, const int&)> cmp = [&score](const int& a, const int& b){
            return score[a] > score[b];
        };
        sort(idx.begin(), idx.end(), cmp);

        vector<string> ans(n);
        /*
        ans[ idx[0] ] = "Gold Medal";
        ans[ idx[1] ] = "Silver Medal";
        ans[ idx[2] ] = "Bronze Medal";
        */
        if(0<n) ans[ idx[0] ] = "Gold Medal";
        if(1<n) ans[ idx[1] ] = "Silver Medal";
        if(2<n) ans[ idx[2] ] = "Bronze Medal";

        for(int i=3;i<n;i++){
            ans[ idx[i] ] = to_string(i+1);
        }

        return ans;
    }
};
