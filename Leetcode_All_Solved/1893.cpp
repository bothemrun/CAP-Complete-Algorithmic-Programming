class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        //NOTE: 1D Sweeep Line Algo
        const int max_range = 52;
        vector<int> covered (max_range, 0);
        for(const vector<int>& range:ranges){
            int left_i = range[0], right_i = range[1];
            covered[left_i]++;
            covered[right_i + 1]--;
        }
        
        for(int i=1;i<max_range;i++){
            covered[i] += covered[i-1];
        }
        
        for(int i=left;i<=right;i++)if(covered[i] <= 0)return false;
        return true;
    }
};
