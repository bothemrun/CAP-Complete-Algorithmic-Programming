class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();

        string ans = s;
        for(int i=0;i+1<n;i++)if(s[i]%2 == s[i+1]%2){
            string t = s;
            swap(t[i], t[i+1]);

            ans = min(ans, t);
        }
        return ans;
    }
};
