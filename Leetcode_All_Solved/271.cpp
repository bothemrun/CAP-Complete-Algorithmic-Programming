//m0
//length prefix encoding.
//let delimiter = "$", s = "abc" --> "3$abc"
//inspiration: huffman code

//even if the original string contains substrings similar to the length prefix,
//like original: "a1$" --> "3$a1$", still ok.
//(1) 'cuz the length is in front of the similar substring.
//(2) the length tells out where the original string ends.

#include<assert.h>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Codec {
public:
    const string delim = "$";

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string code = "";
        for(const string& s: strs)
            code += to_string((int)s.size()) + delim + s;
        return code;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int size = s.size();

        int start = 0;
        while(start<size){
            int delim_i = s.find(delim, start);
            assert(delim_i != string::npos);

            int len_prefix_len = (delim_i-1) - (start-1);
            assert(len_prefix_len >= 1);
            int str_len = stoi( s.substr(start, len_prefix_len) );

            int str_start = delim_i + 1;
            int str_end = delim_i + str_len;
            assert(str_end < size);
            strs.push_back( s.substr(str_start, str_len) );

            //update
            start = str_end + 1;
        }

        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
