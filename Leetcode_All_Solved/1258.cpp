#define MAX_STR 30
#include<unordered_map>
#include<sstream>
class Solution {
public:
    unordered_map<string, int> dict;
    inline int s2i(const string& s){
        if(dict.count(s) != 0)return dict[s];
        
        return dict[s] = dict.size();
    }

    vector<int> set;
    int set_find(const int& a){
        if(set[a] == (-1))return a;
        return set[a] = set_find(set[a]);
    }
    void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a != b) set[a] = b;
        //NOTE: in case of set[a] == (-1)
    }

    vector<string> ans;
    string ans1 = "";
    void backtrack(const vector<int>& text_i, int i, unordered_map<int, vector<string>> syno){
        if(i == text_i.size()){
            //pack
            ans.push_back(ans1);
            return;
        }

        int set_i = set_find(text_i[i]);
        for(const string& w: syno[set_i]){
            string old_ans1 = ans1;
            ans1 += w;
            if(i != text_i.size()-1) ans1 += " ";

            backtrack(text_i, i+1, syno);

            ans1 = old_ans1;

        }
    }

    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        
        istringstream ss(text);
        string w;
        vector<int> text_i;
        while(ss >> w){
            text_i.push_back( s2i(w) );
        }

        set = vector<int>(MAX_STR, (-1));

        for(const vector<string>& syn: synonyms)
            set_join( s2i(syn[0]), s2i(syn[1]) );
        
        //sort each set of synonyms
        unordered_map<int, vector<string>> syno;
        for(unordered_map<string,int>::iterator it = dict.begin();it!=dict.end();it++){
            syno[ set_find(it->second) ].push_back(it->first);
        }

        for(unordered_map<int, vector<string>>::iterator it=syno.begin();it!=syno.end();it++){
            sort(it->second.begin(), it->second.end());
        }

        //make answers by backtracking
        backtrack(text_i, 0, syno);
        return ans;
    }
};
