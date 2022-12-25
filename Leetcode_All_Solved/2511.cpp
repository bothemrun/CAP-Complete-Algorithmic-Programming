#include<algorithm>
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int max_cap = 0;
        int n = forts.size();
        int i = 0;
        while(i<n){
            if( forts[i] == 0){
                i++;
                continue;
            }
            
            int j = i+1;
            while(j < n && forts[j] == 0){
                j++;
            }
            
            if(j == n)break;
            
            if(forts[i] * forts[j] == (-1)){
                max_cap = max(max_cap, (j-1) - i );
            }
            
            //update
            i = j;
        }
        return max_cap;
    }
};
