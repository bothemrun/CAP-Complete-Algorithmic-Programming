//m2
//space optim bottom up dp

//NOTE: don't remember the difference info, since we compare 3 adjacent numbers.
//then when calling previous [i-1], then comparison condition would still hold.
#define IDX(i) (((i)%2 + 2)%2)
#define Memo(i) (memo[ IDX(i) ])
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(2, 0);//init i=0,1

        //NOTE: enumerate ending at i
        int cnt = 0;
        for(int i=2;i<n;i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                Memo(i) = 1 + Memo(i-1);
            else Memo(i) = 0;

            cnt += Memo(i);
        }
        return cnt;
    }
};
