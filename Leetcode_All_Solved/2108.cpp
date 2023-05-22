class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(const string& w: words){
            bool palin = true;
            int i=0, j=w.size()-1;
            while(i<j){
                if(w[i++] != w[j--]){
                    palin = false;
                    break;
                }
            }
            if(palin) return w;
        }
        return "";
    }
};
