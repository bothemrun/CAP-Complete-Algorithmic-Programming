//in-place, without copying
#include<algorithm>
#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int left = 0;
        assert(s[left] != ' ');

        int right = 0;
        while(right < n){
            while(right+1<n && s[right+1] != ' ') right++;
            assert( !(right<n) || s[right] != ' ');

            reverse(s.begin() + left, s.begin() + right+1 );

            //update next
            left = right + 2;
            right = left;
        }
    }
};
