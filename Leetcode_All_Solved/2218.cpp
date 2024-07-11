//m0
//the hard part is complexity analysis

//1. def dp(i, k): for j=0~len(piles[i])
//2. seems like O(nkk),
//3. but fix k, (i, j) just go thru all piles[i][j],
//4. so O(k * sum(piles[i].length) ) = O(k*2000) = O(4e6)

class Solution {
public:
    const int notyet = (-1);
    vector<vector<int>> memo;//no overflow

    int choose_skip(const vector<vector<int>>& piles, int i, int cnt){
        if(i<0) return 0;
        if(cnt==0) return 0;

        if(memo[i][cnt] != notyet) return memo[i][cnt];

        int ret = 0;
        int sum = 0;
        for(int choose=0;choose <= min(cnt, (int)piles[i].size() );choose++ ){
            int j = choose-1;
            if(j>=0){
                sum += piles[i][j];
            }

            ret = max(
                ret,
                sum + choose_skip(piles, i-1, cnt - choose)
            );
        }

        return memo[i][cnt] = ret;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        memo.resize(n, vector<int>(k+1, notyet));

        return choose_skip(piles, n-1, k);
    }
};
