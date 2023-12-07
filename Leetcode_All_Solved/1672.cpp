#include<algorithm>

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_w = 0;
        for(const vector<int>& ac: accounts){
            int w = 0;//no overflow
            for(const int& a: ac) w += a;

            max_w = max(max_w, w);
        }

        return max_w;
    }
};
