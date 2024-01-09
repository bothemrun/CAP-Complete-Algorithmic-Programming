#include<algorithm>

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            if( a[0]*a[0] + a[1]*a[1] != b[0]*b[0] + b[1]*b[1] )
                return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
            else
                return a[0]*a[1] < b[0]*b[1];
        };

        auto it = max_element(dimensions.begin(), dimensions.end(), cmp);
        return it->at(0) * it->at(1);
    }
};
