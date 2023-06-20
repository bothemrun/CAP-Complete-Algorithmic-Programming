#include<assert.h>
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        assert(n>=3);
        assert((arr.back() - arr.front()) % n == 0);
        int diff = (arr.back() - arr.front()) / n;

        //NOTE: edge:
        if(diff==0)return arr.front();

        for(int i=0;i<n-1;i++)if(arr[i]+diff != arr[i+1]) return arr[i] + diff;

        assert(false);
        return (-1);
    }
};
