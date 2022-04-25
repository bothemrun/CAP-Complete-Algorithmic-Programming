#include<queue>
#define MOD (1000000000+7)
class cmp_class{
public:
    bool operator()(const int& a, const int& b){
        return a > b;//minheap, also for 0
    }
};
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, cmp_class > minheap;
        for(const int& x:nums)minheap.push(x);
        for(int i=0;i<k;i++){
            int x = minheap.top();
            minheap.pop();
            minheap.push(x+1);
        }
        
        long long ans = 1;
        while(minheap.size() != 0){
            ans *= minheap.top();
            ans %= MOD;
            minheap.pop();
        }
        return (int)ans;
    }
};
