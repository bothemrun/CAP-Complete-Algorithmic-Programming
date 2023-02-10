//NOTE: for j1 <= j2, w1 <= w2, which of the following is smaller?
// max(j1/w1, j2/w2) or max(j2/w1, j1/w2)

//(1) for the second, j2/w1 is the max. so now compare it with the first 2

//(2) j1/w1 <= j2/w1, 'cuz j1 <= j2
//(3) j2/w2 <= j2/w1, 'cuz w1 <= w2
#include<algorithm>
class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        sort(jobs.begin(), jobs.end());
        sort(workers.begin(), workers.end());

        int n = jobs.size();
        int max_day = (-1);
        for(int i=0;i<n;i++){
            max_day = max(max_day, ( (jobs[i]%workers[i] == 0)? jobs[i]/workers[i]:(jobs[i]/workers[i] + 1) ) );
        }

        return max_day;
    }
};
