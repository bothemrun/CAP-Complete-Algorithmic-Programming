//greedy proof:
//1. divide the piles into 3 ascending groups of consecutive coints.

//2. give bob the smallest group

//3. think about which one to pair up with the largest coin (alice will choose it for sure)?
//3.1. so I choose the second largest coin

//detailed proof:
//so which coin to choose to pair up with max1 ? 
//(1) (max1, max2) + (x, y) or
//(2) (max1, x) + (max2, y)
//assume x>y

//so for (1), I get max2+y
//for (2), I get x+y

//so this greedy choice (1) is better.
//and finally we can deduct that pairing neighbors can lead to the optimal solution.

//O(nlogn) due to sorting.

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
    int maxCoins(vector<int>& piles) {
        int n3 = piles.size();
        sort(piles.begin(), piles.end());
        int n = n3 / 3;

        int sum = 0;//no overflow
        for(int i=n;i<n3;i+=2) sum += piles[i];
        return sum;
    }
};
