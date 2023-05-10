#include<algorithm>
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int cnt = 0;
        for(const int& a: arr1){
            //[low, high), B-d <= A <= B+d
            int low = lower_bound(arr2.begin(), arr2.end(), a - d) - arr2.begin();
            int high = upper_bound(arr2.begin(), arr2.end(), a + d) - arr2.begin();

            if( !( low != arr2.size() && low < high ) ) cnt++;
        }

        return cnt;
    }
};
