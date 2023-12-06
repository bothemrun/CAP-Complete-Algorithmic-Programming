//[Greedy Proof]

//[A] greedy two pass
//1. rightward update
//2. leftward update
//3. A.1 is easy to understand, but why won't A.2 disrupt the requirements?

//[B] Why 2nd Pass Will Not Disrupt The Requirements?
//1. for a leftward pass to update, must have rating[i] > rating[i+1]:

//2. (case 1): rating[i-1] goes down (leftwards)
//2.a. so the effect will not propagate any leftwards.

//3. (case 2): rating[i-1] goes up (leftwards)
//3.a. the effeect will propagate leftwards,
//3.b. until it some rating[j] leftwards goes down.

//4. so all the propagation of update are all necessary.

#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);

        for(int i=0;i+1<n;i++)if(ratings[i] < ratings[i+1]){
            candy[i+1] = candy[i] + 1;
        }

        for(int i=n-1;i-1>=0;i--)if(ratings[i-1] > ratings[i]){
            candy[i-1] = max(candy[i-1], candy[i] + 1 );
        }

        int ans = 0; //no overflow
        for(const int& c: candy)
            ans += c;
        return ans;
    }
};
