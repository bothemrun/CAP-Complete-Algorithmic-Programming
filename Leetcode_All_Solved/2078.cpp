#include<algorithm>
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int max_d = 0;
        for(int i=n-1;i>=1;i--)if(colors[i] != colors.front()){
            max_d = max(max_d, i - 0);
            break;
        }
        for(int i=0;i<=n-1-1;i++)if(colors[i] != colors.back()){
            max_d = max(max_d, n-1 - i);
            break;
        }
        return max_d;
    }
};
