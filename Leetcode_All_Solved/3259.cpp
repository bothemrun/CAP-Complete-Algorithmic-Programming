//O(n) dp Basic I
#define Drink(d, i) ( (d==0)? energyDrinkA[i]:energyDrinkB[i] )

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n;
    const long long notyet = (-1);
    vector<vector<long long>> memo;

    long long enum2(const vector<int>& energyDrinkA, const vector<int>& energyDrinkB, int i, int d){
        if(!(i<n)) return 0;

        if(memo[i][d] != notyet) return memo[i][d];

        return memo[i][d] = Drink(d, i) + max(
            enum2(energyDrinkA, energyDrinkB, i+1, d), //same drink
            enum2(energyDrinkA, energyDrinkB, i+2, (d+1)%2 ) //switch drink
        );
    }

    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        n = energyDrinkA.size();
        memo.resize(n, vector<long long>(2, notyet));

        return max(
            enum2(energyDrinkA, energyDrinkB, 0, 0),
            enum2(energyDrinkA, energyDrinkB, 0, 1)
        );
    }
};
