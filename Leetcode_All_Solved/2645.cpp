#define mod 3
class Solution {
public:
    int addMinimum(string word) {
        //edge case: [-1] & [0], [last] & [last+1]
        int cnt = (word.front()-'a') + ('c' - word.back());

        for(int i=0;i<word.size()-1;i++){
            if(word[i] < word[i+1])
                cnt += word[i+1] - word[i] - 1;
            else if(word[i] == word[i+1]) cnt += 2;
            else
                cnt += 2 - (int)(word[i] - word[i+1]);
        }
        return cnt;
    }
};
