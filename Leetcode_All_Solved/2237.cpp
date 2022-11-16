class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        //NOTE: 1D Sweep Line
        vector<int> bright_sweep(n, 0);
        for(vector<int>& light:lights){
            int start = light[0] - light[1];
            int end = light[0] + light[1];
            
            if(start < 0) bright_sweep[0] += 1;
            else bright_sweep[start] += 1;
            
            if(end+1 < n) bright_sweep[end+1] -= 1;
        }
        
        int ans = 0;
        int bright_prefix_sum = 0;
        for(int i=0;i<n;i++){
            bright_prefix_sum += bright_sweep[i];
            if(bright_prefix_sum >= requirement[i]) ans++;
        }
        return ans;
    }
};
