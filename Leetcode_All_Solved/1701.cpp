//O(n)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        long long wait = 0;
        long long avail = 0;
        for(const vector<int>& cus: customers){
            long long arrival = cus[0];
            long long time = cus[1];

            if(arrival >= avail){
                wait += time;
                avail = arrival + time;
            }else{
                wait += time + (avail - arrival);
                avail += time;
            }
        }

        return (double)wait / (double)n;
    }
};
