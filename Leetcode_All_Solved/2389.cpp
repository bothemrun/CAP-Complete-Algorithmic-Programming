#include<algorithm>
#include<utility>
bool cmp_fn(const pair<int,int>& a, const pair<int,int>& b){
    return a.first < b.first;
}

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        sort(nums.begin(), nums.end());
        vector<pair<int,int>> query_idx(m);
        for(int i=0;i<m;i++)
            query_idx[i] = pair<int,int>(queries[i], i);
        sort(query_idx.begin(), query_idx.end(), cmp_fn);

        vector<int> ans(m);
        int high = (-1);
        long long sum = 0;
        for(const pair<int,int>& p: query_idx){
            while(high+1 < n && sum + nums[high+1] <= p.first){
                sum += nums[++high];
            }

            ans[p.second] = high - (-1);
        }
        return ans;
    }
};
