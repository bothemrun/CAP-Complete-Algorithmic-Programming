class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        int n = word.size();
        int i=0;
        while(i<n){
            int j=i;
            while(j+1<n && word[j+1] == word[i]){
                j++;
            }
            
            int len = j - (i-1);
            ans += len-1;
            
            //update
            i = j+1;
        }
        return ans;
    }
};
