#define tii tuple<int, int>
#include<tuple>
#include<queue>

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long unmarked_sum = 0;
        
        auto cmp = [](const tii& a, const tii& b){
            const auto& [av, ai] = a;
            const auto& [bv, bi] = b;
            if(av != bv) return av > bv; //min heap for values
            else return ai > bi; //min heap for indices
        };
        priority_queue< tii, vector<tii>, decltype(cmp) > minheap(cmp);

        for(int i=0;i<n;i++){
            unmarked_sum += (long long)nums[i];
            minheap.push( tii( nums[i], i ) );
        }
        
        vector<bool> marked(n, false);
        
        int m = queries.size();
        vector<long long> ans(m);
        for(int q=0;q<m;q++){
            int index = queries[q][0];
            int k = queries[q][1];
            
            if(marked[index] == false){
                marked[index] = true;
                unmarked_sum -= (long long)nums[index];
            }
            
            for(int t=0;t<k;t++){
                bool done = false;
                while(done == false){
                    if(minheap.size() == 0) break;
                    
                    const auto [v, i] = minheap.top();
                    minheap.pop();
                    
                    if(marked[i] == true) continue;
                    marked[i] = true;
                    
                    done = true;
                    unmarked_sum -= (long long)v;
                }
            }
            
            ans[q] = unmarked_sum;
        }
        
        return ans;
    }
};
