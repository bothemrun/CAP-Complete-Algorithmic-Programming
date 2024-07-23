//m0
//O(n)
#define tii tuple<int,int>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        //cnt := the number as the right endpoint, the count of such good subarrays.
        //no overflow
        //132 strictly decreasing monotonic stack.
        stack<tii> monosta_cnt;
        for(const int& x: nums){
            long long cur_cnt = 0;

            while(monosta_cnt.size() && !( get<0>( monosta_cnt.top() ) > x ) ){
                auto [last_val, last_cnt] = monosta_cnt.top();
                if(last_val == x){
                    cur_cnt = 1 + last_cnt;
                }

                monosta_cnt.pop();
            }

            monosta_cnt.push(tii(x, cur_cnt));
            ans += cur_cnt;
        }
        return ans + n;
    }
};
