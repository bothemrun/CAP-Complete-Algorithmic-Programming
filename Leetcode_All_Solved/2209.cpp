//m0
//O(n * numCarpets) = 1e6
class Solution {
public:
    int n;
    int carpet_len;
    const int notyet = (-1);
    vector<vector<int>> memo;

    int jump(const string& floor, int i, int cnt){
        if(i>=n) return 0;

        if(memo[i][cnt] != notyet) return memo[i][cnt];

        //choose or skip
        int ret = INT_MAX;
        if(floor[i] == '0'){
            ret = jump(floor, i+1, cnt);
        }else{
            ret = 1 + jump(floor, i+1, cnt);

            if(cnt>=1){
                ret = min(
                    ret,
                    jump(floor, i + carpet_len, cnt-1)
                );
            }
        }
        return memo[i][cnt] = ret;
    }

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        this->n = floor.size();
        this->carpet_len = carpetLen;

        memo.resize(n, vector<int>(numCarpets+1, notyet));
        return jump(floor, 0, numCarpets);
    }
};
