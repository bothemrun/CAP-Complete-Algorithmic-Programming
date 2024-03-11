#include<algorithm>
class Solution {
public:
    string customSortString(string order, string s) {
        int rank[256] = {0};
        for(int i=0;i<(int)order.size();i++){
            rank[ order[i] ] = i;
        }

        auto cmp = [&rank](const char& a, const char& b){
            return rank[a] < rank[b];
        };

        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
