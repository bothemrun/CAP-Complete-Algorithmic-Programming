#define bp batteryPercentages
#include<algorithm>

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int n = bp.size();
        int tested = 0;
        int decrease = 0;
        
        for(const int& b: bp)if( max(0, b - decrease) > 0 ){
            tested++;

            decrease++;
        }
        return tested;
    }
};
