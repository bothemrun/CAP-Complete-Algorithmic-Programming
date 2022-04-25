#include<queue>
#include<unordered_map>
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> val2cnt;
        for(const int& x:arr){
            auto it = val2cnt.find(x);
            if(it != val2cnt.end())it->second++;
            else val2cnt[x] = 1;
        }
        
        priority_queue<int,vector<int>> maxheap;
        for(auto it = val2cnt.begin();it != val2cnt.end();it++)maxheap.push(it->second);
        
        int ans = 0;
        int arr_size = arr.size();
        while(2*arr_size > arr.size()){
            arr_size -= maxheap.top();
            maxheap.pop();
            ans++;
        }
        return ans;
    }
};
