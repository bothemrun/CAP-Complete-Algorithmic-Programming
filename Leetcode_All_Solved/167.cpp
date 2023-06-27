//two pointer squeeze matrix & triangle, 
//https://leetcode.com/problems/container-with-most-water/solutions/6099/yet-another-way-to-see-what-happens-in-the-o-n-algorithm/

#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i=0, j=n-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target) return vector<int>({i+1, j+1});
            else if(numbers[i]+numbers[j] < target) i++;
            else j--;
        }

        assert(false);
        return vector<int>({-1,-1});
    }
};
