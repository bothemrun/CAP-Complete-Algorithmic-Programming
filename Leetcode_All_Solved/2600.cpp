#include<algorithm>
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;
        vector<int> num = {numOnes, numZeros, numNegOnes};
        for(int i=0;i<num.size();i++){
            int take = min(k, num[i]);
            k -= take;
            sum += take*(1-i);
            if(!k)break;
        }
        return sum;
    }
};
