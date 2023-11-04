//O(n) brainteaser
//two ants with opposite directions meeting,
//equals twos ants moving in their same directions.

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        auto it1 = min_element(right.begin(), right.end());
        auto it2 = max_element(left.begin(), left.end());

        return max(
            (it1==right.end())? 0:( n - *it1 ),
            (it2==left.end())? 0:( *it2 - 0 )
        );
    }
};
