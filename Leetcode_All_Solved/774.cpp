//O( log(D/delta) * n ),
//where D := 1e8 station x-axis range,
//delta := 1e-6

//good problem of binary search on floating point numbers.

//However, if k small and n >>> D, then heap of distances between stations, 
//with O(k logn) will be the choice.

#define max_diff ((double)1e8)
#define delta ((double)1e-6)
#include<math.h>

class Solution {
public:
    inline bool valid(const vector<int>& stations, int k, const double& max_dist){
        int n = stations.size();
        for(int i=0;i<n-1;i++){
            double dist = stations[i+1] - stations[i];
            if(dist <= max_dist) continue;

            int need = ceil(dist / max_dist) - 1;
            k -= need;
            if(k < 0) return false;
        }
        return true;
    }

    double binary(const vector<int>& stations, const int& k, const double& low, const double& high){
        double mid = low + (high-low)/2.0;
        bool mid_valid = valid(stations, k, mid);
        if(mid_valid && valid(stations, k, mid-delta)==false) return mid;

        if(mid_valid)
            return binary(stations, k, low, mid);
        else return binary(stations, k, mid+delta, high);
    }

    double minmaxGasDist(vector<int>& stations, int k) {
        return binary(stations, k, 0, max_diff);
    }
};
