#include<algorithm>
class Solution {
private:
    static bool cmp_ptr(const int& a, const int& b){
        return a < b;//max heap
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end(), cmp_ptr);//max heap
        for(int i=0;i<k-1;i++){
            pop_heap(nums.begin(), nums.end(), cmp_ptr); nums.pop_back();
        }
        return nums.front();
    }
};
