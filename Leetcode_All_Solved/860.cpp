class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(const int bill: bills){
            if(bill == 5)five++;
            else if(bill == 10){
                if(five == 0)return false;
                five--;
                ten++;
            }else{
                //NOTE: ten first, then five
                if(ten == 0){
                    if(five < 3)return false;
                    five -= 3;
                }else{
                    ten--;
                    if(five == 0)return false;
                    five--;
                }
            }
        }
        return true;
    }
};
