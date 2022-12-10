#include<limits.h>
#include<algorithm>
bool cmp_fn(const int& a, const int& b){
    return a > b;
}
class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adjlist(n, vector<int>());
        for(const vector<int>& edge: edges){
            adjlist[edge[0]].push_back( vals[edge[1]] );
            adjlist[edge[1]].push_back( vals[edge[0]] );
        }
        for(int i=0;i<n;i++)
            sort(adjlist[i].begin(), adjlist[i].end(), cmp_fn);
        
        //
        int max_star_sum = INT_MIN;
        for(int i=0;i<n;i++){
            int star_sum = vals[i];
            for(int j=0;j<adjlist[i].size();j++){
                if( !(j<k) )break;
                
                if(adjlist[i][j] < 0)break;//NOTE
                star_sum += adjlist[i][j];
            }
            max_star_sum = max(star_sum, max_star_sum);
        }
        return max_star_sum;
    }
};
