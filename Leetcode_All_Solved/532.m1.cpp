//m1
//1 pass (optim from 2 pass linear)
#include<unordered_set>
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> prefix_set;
        unordered_set<int> counted_small_num;

        int cnt = 0;
        for(const int& num: nums){
            for(int sign = 1;sign>=(-1);sign -= 2){
                //NOTE: ok for k == 0
                if(prefix_set.count(num + k*sign) != 0 && 
                counted_small_num.count( 
                    min(num + k*sign, num)
                ) == 0 ){
                    cnt++;
                    counted_small_num.insert(
                        min(num + k*sign, num)
                    );
                }
            }

            //update
            prefix_set.insert(num);
        }
        return cnt;
    }
};
