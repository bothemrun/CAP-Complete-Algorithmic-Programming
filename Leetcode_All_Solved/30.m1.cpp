//m1
//sliding window. O(each shift * all sub-windows * hash cost) = O(b * (n/b) * b) = O(nb)
//since a <= b, so O(a * b) hashing cost is omitted.

//NOTE: pitfall:
//when changing the match_subwindow count, insteaad of +1 / -1, it's += / -= the count in the hash map.

//NOTE: pitfall:
//hash map inserts (key, 0) if key not found,
//so the 2 hash maps may has 0 == 0, and increment the match_subwindow count.

#include<assert.h>
#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int n, a, b, ab;
    vector<int> ans;
    unordered_map<string, int> word2cnt;

    inline void check_slides(const string& s, const int& shift){

        //make the initial window
        if(!(shift + ab-1 < n)) return;
        unordered_map<string, int> cnt;
        for(int i=0;i<a;i++)
            cnt[ s.substr(shift + i*b, b) ]++;
        
        //count the initial match
        int match = 0;
        for(const auto& [key, val]: word2cnt)if(val != 0 && cnt[key] == val)
            match += val;//NOTE: not += 1
        

        //sliding sub-windows
        for(int left=shift;left + ab-1 < n;left += b){
            if(match == a) ans.push_back(left);

            
            int next_right = left + ab;
            if(!(next_right < n)) break;


            //update next for the old left
            const string& s_left = s.substr(left, b);
            int correct_left = word2cnt[s_left];
            int& cnt_left = cnt[s_left];

            assert(cnt_left >= 1);
            if(correct_left != 0 && correct_left == cnt_left)
                match -= correct_left;//NOTE: not -= 1
            
            assert( --cnt_left >= 0 );
            if(correct_left != 0 && correct_left == cnt_left)//NOTE: must check cnt != 0, since hash map inserts if not found key
                match += correct_left;
            
            //update next for the next right
            const string& s_right = s.substr(next_right, b);
            int correct_right = word2cnt[s_right];
            int& cnt_right = cnt[s_right];

            if(correct_right != 0 && correct_right == cnt_right)
                match -= correct_right;
            
            assert( ++cnt_right >= 1 );
            if(correct_right != 0 && correct_right == cnt_right)
                match += correct_right;
        }
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        n = s.size();
        a = words.size();
        b = words.back().size();
        ab = a * b;

        for(const string& word: words)
            word2cnt[word]++;
        

        for(int shift=0;shift<b;shift++)
            check_slides(s, shift);
        return ans;
    }
};
