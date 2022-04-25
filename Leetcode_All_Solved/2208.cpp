#include<queue>
class cmp_class{
public:
    bool operator()(const double& a, const double& b){
        return a < b;//max heap
    }
};
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue< double, vector<double>, cmp_class > max_heap;
        double sum = 0;
        for(const int& x:nums){
            max_heap.push((double)x);
            sum += x;
        }
        double old_sum = sum;
        int ans = 0;
        while( !(2*sum <= old_sum) ){
            double x = max_heap.top();
            max_heap.pop();
            max_heap.push( x/2 );
            sum -= x/2;
            ans++;
        }
        return ans;
    }
};
