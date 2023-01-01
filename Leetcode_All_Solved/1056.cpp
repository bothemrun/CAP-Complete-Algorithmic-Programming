#include<unordered_map>
class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<int, int> valid(
            { {0,0}, {1,1}, {6,9}, {8,8}, {9,6} }
        );
        
        int rotate = 0;
        int x = n;
        while(x != 0){
            if(valid.count(x%10) == 0)return false;

            rotate = rotate * 10 + valid[x%10];

            x /= 10;
        }
        
        if(rotate == n)return false;
        return true;
    }
};
