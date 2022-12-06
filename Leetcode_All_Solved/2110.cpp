class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long cnt = 1;
        int smooth_low = 0;
        for(int i=1;i<n;i++){
            if(prices[i-1] == prices[i] + 1){
                cnt += i - (smooth_low - 1);
            }else{
                cnt++;
                smooth_low = i;
            }
        }
        return cnt;
    }
};
