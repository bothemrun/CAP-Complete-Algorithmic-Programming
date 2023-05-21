#include<algorithm>
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int high = (-1);
        for(int i=0;i<n;i++)if(word[i] == ch){
            high = i;
            break;
        }
        if(high == (-1)) return word;

        int i=0, j=high;
        while(i < j){
            swap( word[i++], word[j--] );
        }
        return word;
    }
};
