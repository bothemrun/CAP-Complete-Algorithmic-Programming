
#include<utility>
#include<algorithm>
class Solution {
public:
    vector<vector<pair<int,int>>> children;

    pair<long long, long long> post(const int& root){
        int k = children[root].size();
        vector<pair<long long, long long>> sum(k);
        long long all_sum = 0;
        for(int i=0;i<k;i++){
            sum[i] = post(children[root][i].first);

            all_sum += max(sum[i].first, sum[i].second);
        }

        long long sum1 = all_sum;
        for(int i=0;i<k;i++){
            sum1 = max(sum1, 
                all_sum -
                max(sum[i].first, sum[i].second) +
                sum[i].first +
                children[root][i].second
            );
        }

        //NOTE: if no children, then (0, 0)
        return pair<long long, long long>(
            max(all_sum, (long long)0),
            max(sum1, (long long)0)
        );

    }

    long long maxScore(vector<vector<int>>& edges) {
        int n = edges.size();
        children = vector<vector<pair<int,int>>>(n, vector<pair<int,int>>() );
        for(int i=1;i<n;i++)
            children[ edges[i][0] ].push_back( pair<int,int>(i, edges[i][1] ) );

        pair<long long, long long> sum = post(0);
        return max(sum.first, sum.second);
    }
};



