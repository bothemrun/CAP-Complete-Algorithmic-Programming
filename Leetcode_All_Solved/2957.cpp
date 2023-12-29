//greedy
class Solution {
public:
    inline bool adj(char a, char b){
        if(a==b) return true;
        if(a+1==b || a==b+1) return true;
        return false;
    }
    int removeAlmostEqualCharacters(string word) {
        int n = word.size();
        int ans = 0;
        int i=0;
        while(i<n){
            int start = i;
            while(i+1<n && adj(word[i], word[i+1]) ){
                i++;
            }
            int end = i;
            int len = end - (start-1);

            ans += len / 2;

            //update
            i++;
        }

        return ans;
    }
};
