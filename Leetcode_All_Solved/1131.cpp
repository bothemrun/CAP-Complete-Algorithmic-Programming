//1. (x, y) to new coordinates (a, b) = (x+y, x-y)

//2. manhattan distance = chebyshev distance of (a, b) = max(|a1-a2|, |b1-b2|)

//3. for 3D:
//a. apply +z/-z to (x+y, x-y) 
//b. (x+y +z, x+y -z, x-y +z, x-y -z)


//4. see
//a. see my Leetcode Log notes
//b. https://codeforces.com/blog/entry/57534
//c. karutz: https://leetcode.com/problems/maximum-of-absolute-value-expression/solutions/347046/python-manhattan-chebyshev-distance/
//d. goelrishabh5: https://leetcode.com/problems/maximum-of-absolute-value-expression/

#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    inline int find_max_diff(const vector<int>& p){
        return 
            *max_element(p.begin(), p.end()) -
            *min_element(p.begin(), p.end());
    }

    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();

        //(x+y +z, x+y -z, x-y +z, x-y -z)
        vector<vector<int>> p(4, vector<int>(n));
        for(int i=0;i<n;i++){
            int x = arr1[i];
            int y = arr2[i];
            int z = i;

            p[0][i] = x+y +z;
            p[1][i] = x+y -z;
            p[2][i] = x-y +z;
            p[3][i] = x-y -z;
        }

        int max_manhattan = 0;
        for(int d=0;d<4;d++){
            max_manhattan = max(
                max_manhattan,
                find_max_diff(p[d])
            );
        }

        return max_manhattan;
    }
};
