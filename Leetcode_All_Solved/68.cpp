#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;

        int i = 0;
        while(i<n){
            int left = i;
            //1. find most words in a line before padding, each word with only 1 space.
            int len = 0;
            while(i<n && len + words[i].size() + 1 <= maxWidth + 1){
                len += words[i].size() + 1;
                i++;
            }
            int right = i - 1;
            assert(left <= right);


            //2. calculate the padding spaces for each word
            if(i==n){
                //last line
                string line = "";
                for(int j=left;j<=right;j++){
                    if(j==right) line += words[j];
                    else line += words[j] + " ";
                }

                //pad the remaining
                while(line.size() < maxWidth) line += " ";

                assert(line.size() == maxWidth);

                ans.push_back(line);
                break;
            }


            //not the last line, calculate the padding spaces
            string line = "";
            //words except the last word.
            int space = maxWidth;
            for(int j=left;j<=right;j++) space -= (int)words[j].size();
            assert(space >= 0);

            int word_cnt = right - (left-1);
            if(word_cnt != 1){
                
                int space1 = space / (word_cnt - 1);
                int space_remainder = space % (word_cnt - 1);
                for(int j=left;j<right;j++){
                    line += words[j];
                    for(int k=0;k<space1;k++) line += " ";
                    if(space_remainder > 0){
                        space_remainder--;
                        line += " ";
                    }
                }
            }

            //the last word in a line
            line += words[right];
            while(line.size() < maxWidth) line += " ";

            assert(line.size() == maxWidth);

            ans.push_back(line);



            //3. next
            i = right + 1;
        }

        return ans;
    }
};
