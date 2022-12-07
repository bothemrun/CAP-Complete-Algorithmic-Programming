//nums[i] = 1~1e4, nums.size() <= 2*1e4, so O(1e4) is the same as O(nums.size()), not introducing O(nlogn) sorting.
#define LIM 1e4 
#include<algorithm>
class Solution {
public:
    inline int house_robber(const vector<int>& money){
        int n = money.size();
        vector<vector<int>> dp_seen(n, vector<int>(2));
        //NOTE: 0: not robbed, 1: robbed this index
        dp_seen[0] = {0, money[0]};//nums.length>=1
        for(int i=1;i<n;i++){
            dp_seen[i][0] = max(dp_seen[i-1][1], dp_seen[i-1][0]);
            dp_seen[i][1] = money[i] + dp_seen[i-1][0];
            //printf("(%d,%d) ", dp_seen[i][0], dp_seen[i][1]);
        }
        //cout << endl;
        
        return max(dp_seen.back()[0], dp_seen.back()[1]);
    }

    int deleteAndEarn(vector<int>& nums) {
        vector<int> num2cnt(LIM+1, 0);
        int real_low = LIM, real_high = 1;
        for(const int& num: nums){
            num2cnt[num]++;
            real_low = min(real_low, num);
            real_high = max(real_high, num);
        }

        
        vector<int> house_money;
        for(int i=real_low;i<=real_high;i++){
            if(num2cnt[i] != 0) house_money.push_back(i * num2cnt[i]);
            else{//NOTE: 0 padding
                house_money.push_back(0);
                //NOTE: while(i <= real_high && num2cnt[i] == 0) i++;
                while(i+1 <= real_high && num2cnt[i+1] == 0) i++;
            }
        }
        
        /*for(const int& money: house_money) cout << money << " ";
        cout << "\n";*/

        //NOTE: house robber on house_money
        return house_robber(house_money);
    }
};






