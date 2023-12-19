#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img.back().size();
        vector<int> di = {-1, 0, 1};
        vector<int> dj = {-1, 0, 1};

        vector<vector<int>> smooth(m, vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){

                int pixel = 0;
                int valid = 0;

                for(const int& dx: di)
                    for(const int& dy: dj){
                        int x = i+dx;
                        int y = j+dy;
                        if( !(0<=x && x<m && 0<=y && y<n) ) continue;

                        valid++;
                        pixel += img[x][y];
                    }
                
                smooth[i][j] = pixel / valid;
            }
        
        return smooth;
    }
};
