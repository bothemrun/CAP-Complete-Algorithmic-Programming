class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<vector<int>> dp_ending2(n, vector<int>(2, 0));
        //NOTE: 0: ascending, 1: descending
        int cnt = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(rating[j] < rating[i]){
                    cnt += dp_ending2[j][0];

                    dp_ending2[i][0]++;
                }else if(rating[j] > rating[i]){
                    cnt += dp_ending2[j][1];

                    dp_ending2[i][1]++;
                }
            }
        }
        return cnt;
    }
};
