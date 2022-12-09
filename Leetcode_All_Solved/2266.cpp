#define MOD ((long long)(1e9 + 7))
#include<unordered_map>
class Solution {
public:
    vector<int> wordDictLen;
    inline void make_dict(){
        wordDictLen = vector<int>(9+1);
        for(int i=2;i<=9;i++){
            wordDictLen[i] = ( (i==7 || i==9)? 4:3 );
        }
    }

    long long word_break_dfs(int num, int num_cnt, vector<unordered_map<int, long long>>& dp){
        if(dp[num].count(num_cnt) != 0)return dp[num][num_cnt];

        dp[num][num_cnt] = 0;
        for(int len=1;len<=wordDictLen[num];len++){
            int new_num_cnt = num_cnt - len;
            if(new_num_cnt == 0) dp[num][num_cnt]++;
            else if(new_num_cnt < 0)continue;
            else{
                dp[num][num_cnt] += word_break_dfs(num, new_num_cnt, dp);
                dp[num][num_cnt] %= MOD;
            }
        }
        return dp[num][num_cnt]%MOD;
    }

    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        make_dict();

        vector<unordered_map<int, long long>> dp(9+1, unordered_map<int, long long>() );
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
