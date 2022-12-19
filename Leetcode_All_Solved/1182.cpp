#define COLOR 3
#include<algorithm>
#include<limits.h>
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> dist2color(n, vector<int>(COLOR + 1));

        //NOTE: forward pass, prefix min
        vector<int> prefix_min(COLOR + 1, INT_MAX);
        for(int i=0;i<n;i++){
            for(int j=1;j<=COLOR;j++){
                if(colors[i] == j) prefix_min[j] = 0;
                else if(i == 0 || prefix_min[j] == INT_MAX);
                else prefix_min[j]++;

                dist2color[i][j] = prefix_min[j];
            }
        }

        //NOTE: backward pass, suffix min
        vector<int> suffix_min(COLOR + 1, INT_MAX);
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=COLOR;j++){
                if(colors[i] == j) suffix_min[j] = 0;
                else if(i == n-1 || suffix_min[j] == INT_MAX);
                else suffix_min[j]++;

                dist2color[i][j] = min(
                    dist2color[i][j],
                    suffix_min[j]
                );
            }
        }

        //answer
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int ans1 = dist2color[ queries[i][0] ][ queries[i][1] ];
            ans[i] = ( (ans1==INT_MAX)? (-1):ans1 );
        }
        return ans;
    }
};


