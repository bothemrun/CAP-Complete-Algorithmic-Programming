#include<algorithm>
class Solution {
public:
    int gcd(int a, int b){
        //assume a >= b
        if(a < b)return gcd(b, a);
        if(b == 0)return a;
        else return gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        return gcd(
            *max_element(nums.begin(), nums.end()),
            *min_element(nums.begin(), nums.end())
        );
    }
};
