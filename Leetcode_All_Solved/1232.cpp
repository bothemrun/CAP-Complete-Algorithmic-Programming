#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(coordinates[0][0] == coordinates[1][0]){
            //vertical line
            for(int i=2;i<n;i++)if(coordinates[i][0] != coordinates[0][0]) return false;
            return true;
        }else{
            double slope = (double)(coordinates[1][1] - coordinates[0][1]) / (double)(coordinates[1][0] - coordinates[0][0]);
            for(int i=2;i<n;i++)
                if( (double)(coordinates[i][1] - coordinates[0][1]) / (double)(coordinates[i][0] - coordinates[0][0]) != slope)
                    return false;
            return true;
        }
    }
};
