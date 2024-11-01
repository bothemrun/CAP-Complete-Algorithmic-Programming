static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.size();
        int i=0;
        while(i<n){
            int j=i;
            while(j+1<n && s[i] == s[j+1]){
                j++;
            }

            ans += s[i];
            if(j - (i-1) >= 2) ans += s[i];

            //update
            i = j+1;
        }
        return ans;
    }
};
