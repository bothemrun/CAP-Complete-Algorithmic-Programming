//m0
//backtracking O(2^words.size) = O(2^14) = O(2e4)
//all distinct subset, choose or not.

class Solution {
public:
    int n;
    int max_score = 0;

    void backtrack(const vector<string>& words, vector<int>& letter_cnt, const vector<int>& score, const int& i, int cur_score){
        if(i==n){
            max_score = max(max_score, cur_score);
            return;
        }

        //NOTE: choose or not.
        backtrack(words, letter_cnt, score, i+1, cur_score);

        bool sufficient = true;
        for(const char& c: words[i]){
            if(letter_cnt[c - 'a']-- == 0) sufficient = false;

            cur_score += score[c - 'a'];
        }

        if(sufficient) backtrack(words, letter_cnt, score, i+1, cur_score);

        for(const char& c: words[i])
            letter_cnt[c - 'a']++;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();

        vector<int> letter_cnt(26, 0);
        for(const char& c: letters)
            letter_cnt[c - 'a']++;
        
        backtrack(words, letter_cnt, score, 0, 0);
        return max_score;
    }
};
