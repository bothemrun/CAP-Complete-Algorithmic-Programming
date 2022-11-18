#include<algorithm>//sort()
bool cmp_fn(const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
}
class Solution {
public:
    int set_find(const int& a, vector<int>& set){
        if(set[a] == (-1))return a;
        return (set[a] = set_find(set[a], set));
    }
    void set_join(int a, int b, vector<int>& set, int& set_cnt){
        a = set_find(a, set);
        b = set_find(b, set);
        if(a != b){
            set[a] = b;
            set_cnt--;
        }
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), cmp_fn);
        
        vector<int> set(n, (-1));
        int set_cnt = n;
        for(const vector<int>& log: logs){
            set_join(log[1], log[2], set, set_cnt);
            if(set_cnt == 1) return log[0];
        }
        return (-1);
    }
};
