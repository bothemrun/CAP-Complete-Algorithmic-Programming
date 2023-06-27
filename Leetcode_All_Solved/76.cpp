//bitmasking >= 2^26 too much, so not DP.

//NOTE: for vectors to count chars, use 256 as its size instead of 26 or 56.
#define charsize 256

#include<limits.h>
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
    vector<int> t_cnt;
    vector<bool> t_has;
    vector<int> redundant;

    inline void unneeded_redundant(int& left, const int& right, const string& s){
        while(left<=right && (
            t_has[ s[left] ]==false ||
            redundant[ s[left] ] > 0
        )){
            if(redundant[ s[left] ] > 0) redundant[ s[left] ]--;

            left++;
        }
        assert(left<=right);
    }

    string minWindow(string s, string t) {
        //1. count t
        t_cnt.resize(charsize, 0);
        t_has.resize(charsize, false);

        for(const char& c: t){
            t_cnt[c]++;
            t_has[c] = true;
        }

        //2. make 1st window
        //NOTE: must handle right end first, then left end, due to redundancy
        redundant.resize(charsize, 0);
        int t_size = t.size();
        int right = 0;
        int n = s.size();
        for(;right<n;right++){
            char c = s[right];

            if(t_cnt[c] > 0){
                t_cnt[c]--;
                if(--t_size == 0) break;
            }else if(t_has[c]==true)
                redundant[c]++;
        }

        //edge
        if(!(right<n)) return "";

        int left = 0;
        unneeded_redundant(left, right, s);

        //3. sliding window
        int min_len = INT_MAX;
        int min_left = INT_MAX;
        bool first_win = true;
        for(;right<n;right++){
            const char& c = s[right];

            if(first_win == true) first_win = false;
            else if(t_has[c]==true && s[left]==c){
                left++;//drop
                assert(redundant[c] == 0);

                //drop more
                unneeded_redundant(left, right, s);
            }else if(t_has[c]==true) redundant[c]++;

            //update min
            int len = right - (left-1);
            if(len < min_len){
                min_len = len;
                min_left = left;
            }
        }

        assert(min_len!=INT_MAX && min_left!=INT_MAX);
        return s.substr(min_left, min_len);
    }
};
