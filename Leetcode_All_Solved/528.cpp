#include<stdlib.h>
class Solution {
    vector<long long> prefix_sum;
    int binary(const int& target, int low, int high){
        int mid = low + (high-low)/2;
        if(mid == 0 && target <= prefix_sum[0])return 0;
        if(mid != 0 && target <= prefix_sum[mid] && prefix_sum[mid-1] < target)return mid;
        //not here:if(low==high)
        
        if(prefix_sum[mid] < target)return binary(target, mid+1, high);
        else return binary(target, low, mid);
    }
public:
    Solution(vector<int>& w) {
        prefix_sum.resize((int)w.size());
        prefix_sum[0] = w[0];
        for(int i=1;i<(int)w.size();i++){
            prefix_sum[i] = prefix_sum[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int r = rand()%prefix_sum.back() + 1;
        return binary(r, 0, prefix_sum.size()-1);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
