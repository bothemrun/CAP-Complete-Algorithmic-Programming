class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pro = 1;
        for(const int& num: nums){
            if(!num)return 0;
            pro *= ((num>0)? 1:(-1) );
        }
        return pro;
    }
};
