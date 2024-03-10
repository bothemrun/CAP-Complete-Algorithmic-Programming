//O(nlogn) due to sorting
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
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        auto cmp = [](const int& a, const int& b){
            return a>b;
        };
        sort(happiness.begin(), happiness.end(), cmp);

        long long sum = 0;
        for(int i=0;i<k;i++){
            sum += max(0, happiness[i] - i);
        }

        return sum;
    }
};
