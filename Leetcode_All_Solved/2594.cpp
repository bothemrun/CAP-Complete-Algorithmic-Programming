#define max_time (100*(long long)1e12)
#include<assert.h>
#include<math.h>
class Solution {
public:
    inline bool enough(const vector<int>& ranks, int cars, long long time){
        for(const int& rank: ranks){
            cars -= (long long)sqrt((double)time / (double)rank);
            if(cars <= 0)return true;
        }
        return false;
    }
    long long binary(const vector<int>& ranks, const int& cars, const long long& low, const long long& high){
        long long mid = low + (high-low)/2;
        bool mid_enough = enough(ranks, cars, mid);
        if(enough(ranks, cars, mid-1) == false && mid_enough == true) return mid;
        assert(low != high);

        if(mid_enough)
            return binary(ranks, cars, low, mid);
        else return binary(ranks, cars, mid+1, high);
    }
    long long repairCars(vector<int>& ranks, int cars) {
        return binary(ranks, cars, 1, max_time);
    }
};
