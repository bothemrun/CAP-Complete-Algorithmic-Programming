#include<limits.h>
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int smallest = INT_MAX;
        int second_smallest = INT_MAX;
        for(const int& x: nums){
            //NOTE: explicitly expand the conditions, to be clear.
            if(x < smallest){
                smallest = x;
            }

            if(smallest < x && x < second_smallest){
                second_smallest = x;
            }

            if(second_smallest < x)return true;
        }

        return false;
    }
};
