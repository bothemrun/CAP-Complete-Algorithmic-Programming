#include<algorithm>
class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long sum = 0;
        int max_d = 0;
        for(const int& d: damage){
            sum += d;
            max_d = max(max_d, d);
        }
        
        if(max_d >= armor)return 1 + sum - armor;
        else return 1 + sum - max_d;
    }
};
