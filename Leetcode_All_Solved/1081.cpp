//O(n)
//greedy:
//if char[i] > char[i+1] and we have char[i] later, then drop char[i] at i.

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        
        int suffix_cnt[256] = {0};
        for(const char& c: s) suffix_cnt[c]++;

        bool used[256] = {0};

        string ans = "";
        for(const char& c: s){
            suffix_cnt[c]--;

            //NOTE: so this char in the answer stack have its same char later(now)
            //NOTE: then by our algorithm,
            //NOTE: the chars in between the last and this same char must be > this char.
            if(used[c] == true) continue;

            while(
                ans.size() != 0 &&
                ans.back() > c &&
                suffix_cnt[ ans.back() ] >= 1
            ){
                used[ ans.back() ] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            used[c] = true;
        }

        return ans;
    }
};
