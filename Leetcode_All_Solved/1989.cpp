//O(n) greedy + two pointers
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

enum TEAM{
    PREY,
    PREDATOR
};

class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        int n = team.size();

        int ans = 0;

        int prey = 0;
        for(int i=0;i<n;i++)if(team[i] == PREDATOR){
            prey = max(prey, i-dist);
            while(
                prey<n &&
                team[prey] != PREY &&
                prey <= i+dist
            ){
                prey++;
            }

            if(prey<n && prey <= i+dist){
                assert(team[prey] == PREY);
                ans++;

                prey++;
            }
        }

        return ans;
    }
};
