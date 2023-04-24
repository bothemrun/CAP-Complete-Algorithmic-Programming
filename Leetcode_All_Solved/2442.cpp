#define max_num ((int)1e6 + 1)
class Solution {
public:
    inline int reverse_num(int num){
        int rev = 0;
        while(num > 0){
            rev = rev*10 + num%10;
            num /= 10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        bool vset[max_num] = {0};
        int cnt = 0;
        for(const int& num: nums){
            if(!vset[num]){
                cnt++;
                vset[num] = true;
            }
            int rev = reverse_num(num);
            if(!vset[rev]){
                cnt++;
                vset[rev] = true;
            }
        }
        return cnt;
    }
};
