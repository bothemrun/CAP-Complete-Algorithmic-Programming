//NOTE: 2 pass
#include<unordered_map>
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> num2cnt;

        int cnt_for_k0 = 0;

        for(const int& num: nums){
            if(num2cnt.count(num) == 0) num2cnt[num] = 1;
            else{
                num2cnt[num]++;

                if(num2cnt[num] == 2) cnt_for_k0++;
            }
        }

        if(k == 0)return cnt_for_k0;

        
        int cnt = 0;
        for(unordered_map<int,int>::iterator it = num2cnt.begin();it != num2cnt.end();it++){
            //NOTE: num1 - num2 == k & num2 - num1 == k are symmetric.
            if(num2cnt.count(it->first + k) != 0) cnt++;
        }

        return cnt;
    }
};
