//generalized for k >= 2
#define max_sum (9*10)
#include<algorithm>
#include<queue>
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a > b;//min heap
    }
};
class Solution {
public:
    inline int sum_digit(int num){
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    inline void push_k(priority_queue<int, vector<int>, cmp_class>& heap, const int& sum, const int& k=2){
        heap.push(sum);
        if(heap.size() > k) heap.pop();
    }
    int maximumSum(vector<int>& nums) {
        vector< priority_queue<int, vector<int>, cmp_class> > sum2max2(max_sum);
        for(const int& num: nums){
            int sum = sum_digit(num);
            push_k(sum2max2[sum], num);
        }

        int max_val = (-1);
        for(auto& heap: sum2max2)if(heap.size() == 2){
            int a = heap.top();
            heap.pop();
            max_val = max(max_val, a + heap.top());
        }
        return max_val;
    }
};
