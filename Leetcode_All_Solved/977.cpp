//follow-up, O(n), not O(nlogn)
#include<algorithm>
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        //NOTE: use binary search for optim
        //NOTE: random access iterator allows it + n, it - n, it2 - it1
        int j = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int i = j - 1;

        //merge 2 sorted
        vector<int> square;

        //NOTE: optim
        /*int square_i = nums[i] * nums[i];
        int square_j = nums[j] * nums[j];*/
        //NOTE: edge case
        int square_i;
        int square_j;
        if(0 <= i) square_i = nums[i] * nums[i];
        if(j < n) square_j = nums[j] * nums[j];
        
        while(0<=i && j<n){
            if(square_i < square_j){
                square.push_back(square_i);
                if(--i >= 0) square_i = nums[i] * nums[i];
            }else{
                square.push_back(square_j);
                if(++j < n) square_j = nums[j] * nums[j];
            }
        }

        while(0<=i){
            square.push_back(nums[i] * nums[i--]);
        }
        while(j<n){
            square.push_back(nums[j] * nums[j++]);
        }

        return square;
    }
};
