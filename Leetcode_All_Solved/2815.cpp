//O(n * d)
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
    int maxSum(vector<int>& nums) {
        vector<vector<int>> max2(11);
        for(int num: nums){
            int x = num;
            int max_digit = 0;
            while(x != 0){
                max_digit = max(max_digit, x%10);
                x /= 10;
            }

            vector<int>& heap = max2[max_digit];
            if(heap.size() < 2)
                heap.push_back(num);
            else if(num > *max_element(heap.begin(), heap.end()) )
                *min_element(heap.begin(), heap.end()) = num;
            else if(num > *min_element(heap.begin(), heap.end()) )
                *min_element(heap.begin(), heap.end()) = num;
        }

        int max_sum = (-1);
        for(int digit=1;digit<=9;digit++)if(max2[digit].size() == 2)
            max_sum = max(
                max_sum,
                max2[digit].front() + max2[digit].back()
            );
        return max_sum;
    }
};
