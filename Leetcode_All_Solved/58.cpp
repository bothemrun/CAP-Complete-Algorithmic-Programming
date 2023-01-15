class Solution {
public:
    int lengthOfLastWord(string s) {
        int high = s.size()-1;
        while(high>=0 && s[high] == ' ')high--;

        int space = high;
        for(;space>=0;space--)if(s[space] == ' ')break;
        return high - space;
    }
};
