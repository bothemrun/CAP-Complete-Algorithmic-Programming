class Solution {
public:
    inline int find_1st_mismatch(const vector<int>& num, const int& x){
        for(int i=num.size()-1;i>=0;i--)if(num[i] != x) return num[i];
        //NOTE: edge case: all 999...99, then remain the same
        return (-1);
    }

    inline int remap(const vector<int>& num, const int& before, const int& after){
        int x = 0;
        for(int i=num.size()-1;i>=0;i--){
            x *= 10;
            if(num[i] == before) x += after;
            else x += num[i];
        }
        return x;
    }

    int minMaxDifference(int num) {
        vector<int> digit;
        int x = num;
        while(x > 0){
            digit.push_back(x%10);
            x /= 10;
        }
        int max_change = find_1st_mismatch(digit, 9);
        int max_num;
        if(max_change == (-1)) max_num = num;
        else max_num = remap(digit, max_change, 9);

        //NOTE: the number before remapping can't have leading zeros.
        int min_change = digit.back();
        //NOTE: num != 0
        int min_num = remap(digit, min_change, 0);

        return max_num - min_num;
    }
};
