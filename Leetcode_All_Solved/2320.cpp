#define MOD (1e9 + 7)
class Solution {
public:
    inline unsigned long long house_robber_comb(const int& n){
        vector<unsigned long long> prev_comb({1, 1});
        //NOTE: 0: not robbed/no house, 1: robbed/has house
        for(int i=1;i<n;i++){
            unsigned long long no_house = (prev_comb[0] + prev_comb[1])%(unsigned long long)MOD; //prev_comb[0] + prev_comb[1];
            unsigned long long has_house = prev_comb[0]%(unsigned long long)MOD;
            prev_comb = {no_house, has_house};
        }
        return (prev_comb[0] + prev_comb[1])%(unsigned long long)MOD;
    }
    int countHousePlacements(int n) {
        unsigned long long houserobber = house_robber_comb(n);
        return (houserobber * houserobber)%(unsigned long long)MOD;
    }
};
