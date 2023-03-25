#define max_weight 5000
#include<algorithm>
class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        int sum = 0;
        int i;
        for(i=0;i<weight.size();i++){
            if(sum + weight[i] <= max_weight){
                sum += weight[i];
            }else break;
        }
        return i;
    }
};
