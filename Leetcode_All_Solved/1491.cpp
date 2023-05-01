#include<algorithm>
class Solution {
public:
    double average(vector<int>& salary) {
        long long sum = 0;
        for(const int& s: salary) sum += s;
        int mi = *min_element(salary.begin(), salary.end());
        int ma = *max_element(salary.begin(), salary.end());
        return (double)(sum - mi - ma) / (double)(salary.size() - 2);
    }
};
