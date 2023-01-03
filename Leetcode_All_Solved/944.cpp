class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs.back().size();
        int cnt = 0;
        for(int j=0;j<m;j++){
            bool sorted = true;
            for(int i=0;i<n-1;i++){
                if(strs[i][j] > strs[i+1][j]){
                    sorted = false;
                    break;
                }
            }

            cnt += sorted;
        }
        return m - cnt;
    }
};
