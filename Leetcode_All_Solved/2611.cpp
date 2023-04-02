#include<algorithm>
bool cmp_fn(const vector<int>& a, const vector<int>& b){
    if(a[0] != b[0]) return a[0] < b[0];
    else if(a[1] != b[1]) return a[1] < b[1];
    else return a[2] > b[2];
}
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<vector<int>> diff(n, vector<int>(3));
        for(int i=0;i<n;i++){
            diff[i] = {reward1[i] - reward2[i], reward1[i], reward2[i]};
        }
        sort(diff.begin(), diff.end(), cmp_fn);
        
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += diff[ n-1 - i ][1];
        }
        for(int i=0;i<(n-k);i++){
            sum += diff[ i ][2];
        }
        return sum;
    }
};
