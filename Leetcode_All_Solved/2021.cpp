#include<algorithm>
#include<utility>//pair
bool cmp_fn(const pair<int,int>& p1, const pair<int,int>& p2){
    //NOTE: return p1.first < p2.first;
    if(p1.first != p2.first) return p1.first < p2.first;
    return p1.second < p2.second;
}
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        vector<pair<int,int>> bright_sweep_change;
        for(const vector<int>& light: lights){
            int start = light[0] - light[1];
            int end = light[0] + light[1];
            
            bright_sweep_change.push_back( pair<int,int>({start, 1}) );
            bright_sweep_change.push_back( pair<int,int>({end + 1, (-1)}) );
        }
        
        sort(bright_sweep_change.begin(), bright_sweep_change.end(), cmp_fn);
        int max_bright = 0;
        int max_bright_pos = 0;
        int bright_prefix_sum = 0;
        for(pair<int,int>& change: bright_sweep_change){
            bright_prefix_sum += change.second;
            
            if(bright_prefix_sum > max_bright){
                max_bright = bright_prefix_sum;
                max_bright_pos = change.first;
            }
        }
        
        return max_bright_pos;
    }
};
