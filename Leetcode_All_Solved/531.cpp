#define max_n 500
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture.back().size();

        bool col_has_black[max_n] = {0};
        bool col_lonely[max_n] = {0};
        for(int i=0;i<m;i++){

            int row_black = 0, row_black_j = (-1);
            const int not_lonely = 2;

            for(int j=0;j<n;j++)if(picture[i][j] == 'B'){
                if(++row_black == 1) row_black_j = j;

                if(col_has_black[j]==true) row_black = not_lonely;
                col_has_black[j] = true;
                col_lonely[j] = false;
            }

            if(row_black != 1) continue;
            col_lonely[row_black_j] = true;
        }

        int cnt = 0;
        for(int j=0;j<n;j++)if(col_lonely[j]==true) cnt++;
        return cnt;
    }
};
