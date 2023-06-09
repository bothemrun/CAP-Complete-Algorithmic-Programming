#define max_arr 1003
class Solution {
public:
    int countElements(vector<int>& arr) {
        int cnt[max_arr] = {0};
        for(const int& a: arr) cnt[a]++;

        int match = 0;
        for(const int& a: arr)if(cnt[a+1] != 0) match++;
        return match;
    }
};
