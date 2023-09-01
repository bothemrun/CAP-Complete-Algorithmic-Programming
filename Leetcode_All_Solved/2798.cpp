class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int cnt = 0;
        for(const int& hour: hours)if(hour >= target) cnt++;
        return cnt;
    }
};
