#include<unordered_map>
class Solution {
public:
    vector<int> set;
    
    unordered_map<string, int> dict;
    inline int s2i(const string& w){
        if(dict.count(w) == 0)
            return dict[w] = dict.size();
        else return dict[w];
    }

    int set_find(const int& i){
        if(set[i] == (-1))return i;
        return set[i] = set_find(set[i]);
    }

    void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a != b) set[a] = b;
        //NOTE: in case of set[a] == (-1) is the root
    }

    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size())
            return false;
        
        set.resize(5000, -1);
        for(const string& w:sentence1)
            s2i(w);
        for(const string& w:sentence2)
            s2i(w);
        
        for(const vector<string>& xy: similarPairs){
            s2i(xy[0]);
            s2i(xy[1]);
            set_join( s2i(xy[0]), s2i(xy[1]) );
        }

        /*for(auto it=dict.begin();it!=dict.end();it++)
            cout << it->first << " " << it->second <<endl;
        for(int i=0;i<10;i++){
            cout << set[i] << " ";
        }*/

        for(int i=0;i<sentence1.size();i++){
            if( set_find( s2i(sentence1[i]) ) != 
                set_find( s2i(sentence2[i]) ) )
                return false;
        }
        return true;
    }
};
