class Solution {
public:
    inline int char2int(char c){
        return (int)(c - 'a');
    }
    inline char int2char(int i){
        return (char)i + 'a';
    }
    int set_find(const int& a, vector<int>& set){
        if(set[a] == (-1))return a;
        return (set[a] = set_find(set[a], set));
    }
    void set_join(int a, int b, vector<int>& set){
        a = set_find(a, set);
        b = set_find(b, set);
        if(a != b){
            if(a < b) set[b] = a;
            else set[a] = b;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> set(26, (-1));
        for(int i=0;i<s1.size();i++)
            set_join( char2int(s1[i]), char2int(s2[i]), set );
        for(char& c: baseStr)
            c = int2char( set_find( char2int(c), set ) );
        return baseStr;
    }
};
