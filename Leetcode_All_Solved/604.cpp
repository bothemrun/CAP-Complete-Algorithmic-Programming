#include<assert.h>
#include<ctype.h>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class StringIterator {
public:
    vector<pair<char, int>> charcnt;
    int charcnt_idx = 0;

    StringIterator(string compressedString) {
        int n = compressedString.size();
        int start = 0;
        while(start < n){
            //[start] is the char, 
            //[start+1, end-1] are digits.and must exist.
            assert( isalpha( compressedString[start] ) );
            int end = start + 1;
            assert(end < n && isdigit( compressedString[end] ) );
            while(end < n && isdigit( compressedString.at(end) )) end++;
            
            assert(start+1 <= end-1 && isdigit(compressedString.at(end-1) ) );

            charcnt.push_back(
                pair<char, int>(
                    compressedString.at(start),
                    stoi(
                        compressedString.substr(start+1,
                        (end-1) - start)
                    )
                )
            );

            //next
            start = end;
        }
    }
    
    char next() {
        if(!hasNext()) return ' ';

        char c = charcnt.at(charcnt_idx).first;
        if(--charcnt.at(charcnt_idx).second == 0 )
            charcnt_idx++;
        return c;
    }
    
    bool hasNext() {
        return charcnt_idx != charcnt.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
