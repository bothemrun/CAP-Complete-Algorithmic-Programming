class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sin = 0, dou = 0;
        for(int x: nums){
            if(x/10 != 0) dou += x;
            else sin += x;
        }

        return sin != dou;
    }
};
