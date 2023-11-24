//recursion with memo, like knapsack dp
//O(maxAmount * n * maxCoupons)
#define notyet (-1)
#include<algorithm>

class Solution {
public:
    vector<vector<vector<int>>> memo;

    int choose_or_not(const vector<int>& price, const vector<int>& tastiness, const int& i, const int& money, const int& coupon){

        if(i==(-1)) return 0;

        if(memo[i][money][coupon] != notyet)
            return memo[i][money][coupon];
        
        //skip
        int ret = choose_or_not(price, tastiness, i-1, money, coupon);

        //choose w/o coupon
        if(money >= price[i])
            ret = max(
                ret,
                tastiness[i] +
                choose_or_not(price, tastiness, i-1, money - price[i], coupon)
            );

        //choose w/ coupon
        if(coupon != 0 && money >= price[i]/2){
            ret = max(
                ret,
                tastiness[i] +
                choose_or_not(price, tastiness, i-1, money - price[i]/2, coupon-1)
            );
        }

        return memo[i][money][coupon] = ret;
    }

    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        int n = price.size();
        memo.resize(n, vector<vector<int>>(maxAmount+1, vector<int>(maxCoupons+1, notyet) ) );

        return choose_or_not(price, tastiness, n-1, maxAmount, maxCoupons);
    }
};
