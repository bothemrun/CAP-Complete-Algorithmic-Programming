#include<assert.h>
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> remainder(value, 0);
        for(const int& x: nums){
            //cout << ( (x%value) + value )%value <<endl;
            remainder[ ( (x%value) + value )%value ]++;
        }
        //cout << endl;
        
        int n = nums.size();
        for(int multi=0;n>0;multi++){
            for(int r=0;r<value;r++){
                if( (remainder[r]--) == 0 )return r + multi * value;
                //n--;
            }
        }
        assert(false);
        return 0;
    }
};
