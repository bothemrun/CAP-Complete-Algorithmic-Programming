#include<algorithm>
bool cmp_fn(const vector<int>& a, const vector<int>& b){
    return (double)a[0]/(double)a[1] > (double)b[0]/(double)b[1];
}
class Solution {
public:
    double maxPrice(vector<vector<int>>& items, int capacity) {
        int n = items.size();
        sort(items.begin(), items.end(), cmp_fn);

        double sum = 0;
        for(const vector<int>& i:items){
            if(capacity >= i[1]){
                capacity -= i[1];
                sum += (double)i[0];
            }else{
                sum += (double)i[0] * (double)capacity / (double)i[1];
                capacity = 0;
            }

            if(capacity == 0)break;
        }

        if(capacity != 0)return (-1.0);
        else return sum;
    }
};
