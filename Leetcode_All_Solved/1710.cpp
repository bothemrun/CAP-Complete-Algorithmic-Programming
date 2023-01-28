#include<algorithm>
bool cmp_fn(const vector<int>& a, const vector<int>& b){
    return a[1] > b[1];//descending
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp_fn);
        int cnt = 0;
        int i = 0;
        while(truckSize > 0 && i < boxTypes.size()){
            int take = min(truckSize, boxTypes[i][0]);
            cnt += take * boxTypes[i][1];
            truckSize -= take;
            i++;
        }
        return cnt;
    }
};



