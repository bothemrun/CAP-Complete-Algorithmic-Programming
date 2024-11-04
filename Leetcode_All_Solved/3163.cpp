static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string ans = "";
        int i=0;
        while(i<n){
            int j = i;
            while(j+1<n && word[i] == word[j+1]){
                j++;
                if(j - (i-1) >= 9) break;
            }

            ans += to_string(j - (i-1)) + word[i];

            //update
            i = j+1;
        }
        return ans;
    }
};
