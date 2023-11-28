//O(n^2)
#define notyet (-1)

class Solution {
public:
    vector<int> memo;
    bool enum_choices(const int& n){
        
        if(memo[n] != notyet) return memo[n];

        for(int x=1;x<n;x++)if(n%x==0){
            if( enum_choices(n-x) == false)
                return memo[n] = true;
        }
        return memo[n] = false;
    }

    bool divisorGame(int n) {
        memo.resize(n + 1, notyet);
        return enum_choices(n);
    }
};
