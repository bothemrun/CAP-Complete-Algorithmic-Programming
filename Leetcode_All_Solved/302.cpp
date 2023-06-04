//m0
//projected onto 1 row. [0, x] is monotonic, so we can do a binary search.
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

enum{
    ROW,
    COL
};

class Solution {
public:
    int m, n;

    inline bool good(const vector<vector<char>>& image, const int& p, const int& orient){
        if(orient == ROW){
            if(!(0<=p && p<n)) return false;

            //traverse this column
            for(int i=0;i<m;i++)if(image[i][p] == '1') return true;
            return false;
        }else{
            if(!(0<=p && p<m)) return false;

            for(int j=0;j<n;j++)if(image[p][j] == '1') return true;
            return false;
        }
    }

    int binary(const vector<vector<char>>& image, const int& low, const int& high, const int& orient, const int& delta=(-1)){

        int mid = low + (high-low)/2;
        int mid_tmp = good(image, mid, orient);
        if( (mid_tmp ^ good(image, mid + delta, orient)) == 1) return mid;
        assert(low != high);

        if( (mid_tmp && delta==(-1)) || (!mid_tmp && delta==1) )
            return binary(image, low, mid, orient, delta);
        else return binary(image, mid+1, high, orient, delta);
    }

    int minArea(vector<vector<char>>& image, int x, int y) {
        m = image.size();
        n = image.front().size();

        int left = binary(image, 0, y, ROW);
        int right = binary(image, y, n-1, ROW, 1);
        int top = binary(image, 0, x, COL);
        int bot = binary(image, x, m-1, COL, 1);
        printf("%d %d %d %d\n", left, right, top, bot);
        return (right-(left-1)) * (bot-(top-1));
    }
};
