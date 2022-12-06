#include<algorithm>
struct flip{
    int flip0;
    int flip1;
};
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<struct flip> dp_ending(n);
        struct flip f0 = {1, 1};
        dp_ending[0] = f0;

        for(int i=1;i<n;i++){
            struct flip fi = {1, 1};
            if(arr[i-1] < arr[i]){
                if(i%2 == 0){
                    fi.flip0 = 1 + dp_ending[i-1].flip0;
                }else{
                    fi.flip1 = 1 + dp_ending[i-1].flip1;
                }
            }else if(arr[i-1] > arr[i]){
                if(i%2 == 1){
                    fi.flip0 = 1 + dp_ending[i-1].flip0;
                }else{
                    fi.flip1 = 1 + dp_ending[i-1].flip1;
                }
            }
            dp_ending[i] = fi;
        }
        
        int max_flip = 0;
        for(int i=0;i<n;i++)
            max_flip = max(max_flip, max(dp_ending[i].flip0, dp_ending[i].flip1 ) );
        return max_flip;
    }
};
