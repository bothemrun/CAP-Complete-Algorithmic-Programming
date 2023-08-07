//m0
//union find on the reversed process. O(n).

//NOTE: not need a priority queue,
//NOTE: 'cuz the currently merged consists of max_sum, then the merged interval must still be the max sum.

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<bool> restored;

    vector<int> dsu;
    vector<int> rank;

    vector<long long> sum;

    inline void make_set(int size, const vector<int>& nums){
        dsu.resize(size);
        for(int i=0;i<size;i++) dsu[i] = i;

        rank.resize(size, 1);

        sum.resize(size);
        for(int i=0;i<size;i++) sum[i] = nums[i];
    }
    int set_find(const int& a){
        if(dsu[a] == a) return a;
        else return dsu[a] = set_find(dsu[a]);
    }
    void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b) return ;

        if(rank[a] < rank[b]){
            dsu[a] = b;

            sum[b] += sum[a];
        }else if(rank[a] > rank[b]){
            dsu[b] = a;

            sum[a] += sum[b];
        }else{
            dsu[a] = b;
            rank[b]++;

            sum[b] += sum[a];
        }
    }

    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();

        make_set(n, nums);

        restored.resize(n, false);

        vector<long long> ans(n);
        ans.front() = 0;
        long long max_sum = 0;
        for(int i=n-1 - 1;i>=0;i--){
            const int& restore_i = removeQueries[i + 1];
            restored[restore_i] = true;

            if(restore_i - 1 >= 0 && restored[restore_i - 1] == true) set_join(restore_i - 1, restore_i);
            if(restore_i + 1 < n && restored[restore_i + 1] == true) set_join(restore_i + 1, restore_i);

            //NOTE: not need a priority queue,
            //NOTE: 'cuz the currently merged consists of max_sum, then the merged interval must still be the max sum.
            max_sum = max(
                max_sum,
                sum[ set_find(restore_i) ]
            );

            ans[i] = max_sum;
        }

        return ans;
    }
};
