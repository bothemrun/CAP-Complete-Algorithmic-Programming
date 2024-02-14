//O(m+n)
#include<assert.h>
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
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int m = encoded1.size();
        int n = encoded2.size();

        int i=0, j=0;
        int x=0, y=0;

        vector<vector<int>> ans;
        while(i<m && j<n){
            int mi = encoded1[i][1];
            int nj = encoded2[j][1];

            int len = min(
                (mi-1) - (x-1),
                (nj-1) - (y-1)
            );

            //trap:
            int val = encoded1[i][0] * encoded2[j][0];
            if(ans.size() && ans.back()[0] == val){
                ans.back()[1] += len;
            }else{
                ans.push_back(vector<int>({val, len}));
            }

            x += len;
            y += len;
            if(x==mi){
                i++;
                x=0;
            }
            if(y==nj){
                j++;
                y=0;
            }
        }

        assert(i==m && j==n);
        return ans;
    }
};
