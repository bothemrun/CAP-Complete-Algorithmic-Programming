class Solution {
public:
    int getLucky(string s, int k) {
        string conv = "";
        for(char c: s) conv += to_string( (c-'a') + 1 );
        for(int t=0;t<k;t++){
            int trans = 0;
            for(char c: conv) trans += c - '0';

            conv = to_string(trans);
        }
        return stoi(conv);
    }
};
