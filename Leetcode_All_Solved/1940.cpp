//O(N)

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int m = arrays.size();

        vector<int> ans;
        vector<int> idx(m, 0);

        for(int j0=0;j0<arrays.front().size();j0++){
            bool common = true;
            for(int i=1;i<m;i++){

                while(idx[i]<arrays[i].size() && arrays[i][ idx[i] ] < arrays.front()[j0]){
                    idx[i]++;
                }

                if(!( idx[i]<arrays[i].size() && arrays[i][ idx[i] ] == arrays.front()[j0] )){
                    common = false;
                    break;
                }
            }

            if(common) ans.push_back(arrays.front()[j0] );
        }

        return ans;
    }
};
