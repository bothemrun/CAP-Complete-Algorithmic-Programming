#include<algorithm>
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for(const vector<int>& e: roads){
            degree[e[0]]++;
            degree[e[1]]++;
        }

        sort(degree.begin(), degree.end());
        long long sum = 0;
        for(int i=n-1;i>=0;i--)
            sum += (long long)(i+1) * (long long)degree[i];
            //NOTE:overflow sum += (i+1) * degree[i];
        return sum;
    }
};
