//m1
//real O(n) by greedy, instead of O(n^2) in m0
class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();

        for(int i=0;i+1<n;i++)if(s[i]%2 == s[i+1]%2 && s[i] > s[i+1]){
            swap(s[i], s[i+1]);
            break;
        }
        return s;
    }
};
