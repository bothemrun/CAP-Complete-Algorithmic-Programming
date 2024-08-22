//O(2^n * n) = O(2^15 * 15) = 5e5
class Solution {
public:
    int n;
    vector<string> ans;
    void backtrack(const string& word, string res, int i){
        if(i>=n){ //not j==n, for j==n-1 in the loop
            ans.push_back(res);
            return;
        }

        backtrack(word, res + word[i], i+1);

        for(int j=i;j<n;j++){
            string tmp = res + to_string(j - (i-1));

            if(j+1<n){
                tmp += word[j+1];
            }

            backtrack(word, tmp, j + 2);
        }
    }
    vector<string> generateAbbreviations(string word) {
        this->n = word.size();
        backtrack(word, "", 0);
        return ans;
    }
};
