//in-place for string s
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    const string delim = " ";
    inline void forward_make_spaces(string& s, const int& word_start, const int& start, const int& end){
        //[start, end), forward
        int len = (end-1) - (start-1);
        for(int i=0;i<len;i++)
            s[word_start+i] = s[start+i];
            
        //make spaces
        for(int i=word_start+len;i<end;i++)
            s[i] = ' ';
    }

    inline void trim(string& s){
        int n = s.size();
        
        int start = 0, end;
        int word_start = 0;
        while((end = s.find(delim, start)) != string::npos){
            if(start == end){
                start = end + delim.size();
                continue;
            }

            forward_make_spaces(s, word_start, start, end);
            
            //update
            int len = (end-1) - (start-1);
            word_start += len+1;
            start = end + delim.size();
        }

        if(start<s.size()){
            forward_make_spaces(s, word_start, start, n);
        }

        //trailing spaces [i, n-1]
        int i = n;
        while(i-1>=0 && s[i-1] == ' ') i--;
        if(i<n) s.erase(i);
    }

    inline void reverse_word(string& s){
        int n = s.size();
        int start = 0, end;
        while((end = s.find(delim, start)) != string::npos){
            int i=start, j=end-1;
            while(i<=j) swap(s[i++], s[j--]);

            start = end + delim.size();
        }
        if(start<n){
            int i=start, j=n-1;
            while(i<=j) swap(s[i++], s[j--]);
        }
    }

    string reverseWords(string s) {
        trim(s);

        reverse_word(s);

        int i=0, j=s.size()-1;
        while(i<=j) swap(s[i++], s[j--]);

        return s;
    }
};
