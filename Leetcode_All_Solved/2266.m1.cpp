//m1
//optim specifically for this problem, not just general leetcode word break problem.
#define MOD ((long long)(1e9 + 7))
#include<unordered_map>
class Solution {
public:
    vector<int> num_optim;
    vector<int> wordDictLen;
    inline void make_dict(){
        //NOTE: 1~9, excluding 7&9, mapped to 0
        // 7 & 9 mapped to 1
        num_optim = vector<int>(1+9, 0);
        num_optim[7] = 1;
        num_optim[9] = 1;
        wordDictLen = vector<int>({3, 4});
    }

    long long word_break_dfs(int num, int num_cnt, vector<unordered_map<int, long long>>& dp){
        int num_optim_mapped = num_optim[num];

        if(dp[num_optim_mapped].count(num_cnt) != 0)return dp[num_optim_mapped][num_cnt];

        dp[num_optim_mapped][num_cnt] = 0;
        for(int len=1;len<=wordDictLen[num_optim_mapped];len++){
            int new_num_cnt = num_cnt - len;
            if(new_num_cnt == 0) dp[num_optim_mapped][num_cnt]++;
            else if(new_num_cnt < 0)continue;
            else{
                dp[num_optim_mapped][num_cnt] += word_break_dfs(num, new_num_cnt, dp);
                dp[num_optim_mapped][num_cnt] %= MOD;
            }
        }
        return dp[num_optim_mapped][num_cnt]%MOD;
    }

    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        make_dict();

        vector<unordered_map<int, long long>> dp(2, unordered_map<int, long long>() );
        long long cnt = 1;//n>=1, so ok
        //find the window of consecutive same values, and multiply them
        int low = 0;
        while(low < n){
            //find window of consecutive same values
            int high = low;

            while(high+1 < n && pressedKeys[low] == pressedKeys[high+1]) high++;

            cnt *= word_break_dfs( stoi(pressedKeys.substr(low, 1) ), high - (low-1), dp)%MOD;
            cnt %= MOD;

            low = high+1;
        }

        return cnt;
    }
};
