//m1
#include<algorithm>
#include<unordered_map>
bool cmp_fn(const vector<int>& v1, const vector<int>& v2){
    //all [0] unique
    return v1[0] < v2[0];
}
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        unordered_map<int,int> bright_sweep_change;
        for(const vector<int>& light: lights){
            int start = light[0] - light[1];
            int end = light[0] + light[1];
            
            if(bright_sweep_change.count(start) == 0)
                bright_sweep_change[start] = 1;
            else bright_sweep_change[start]++;
            //NOTE: end + 1
            if(bright_sweep_change.count(end + 1) == 0)
                bright_sweep_change[end + 1] = (-1);
            else bright_sweep_change[end + 1]--;
        }
        
        vector<vector<int>> sweep_change;
        for(unordered_map<int,int>::iterator it = bright_sweep_change.begin();it != bright_sweep_change.end();it++)
            sweep_change.push_back( vector<int>({it->first, it->second}) );
        sort(sweep_change.begin(), sweep_change.end(), cmp_fn);
        
        int max_bright = 0;
        int max_bright_pos = 0;
        int bright_prefix_sum = 0;
        for(vector<int>& change: sweep_change){
            bright_prefix_sum += change[1];
            
            if(bright_prefix_sum > max_bright){
                max_bright = bright_prefix_sum;
                max_bright_pos = change[0];
            }
        }
        
        return max_bright_pos;
    }
};
