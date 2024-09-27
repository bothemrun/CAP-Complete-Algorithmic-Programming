//m1
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    unordered_map<string, int> s2i_m;
    inline int s2i(const string& s){
        if(s2i_m.find(s) != s2i_m.end()) return s2i_m[s];

        s2i_m[s] = s2i_m.size();
        return s2i_m[s];
    }

    vector<int> dsu;
    vector<int> rank;
    inline void make_set(int size){
        dsu.resize(size);
        for(int i=0;i<size;i++) dsu[i] = i;
        rank.resize(size, 1);
    }
    int set_find(const int& a){
        if(dsu[a] == a) return a;
        return dsu[a] = set_find(dsu[a]);
    }
    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a == b) return;

        if(rank[a] < rank[b]){
            dsu[a] = b;
        }else if(rank[a] > rank[b]){
            dsu[b] = a;
        }else{
            dsu[a] = b;
            rank[b]++;
        }
    }

    inline void split(const string& text, vector<string>& ret, const string& delim){
        int end;
        int start=0;
        while( (end = text.find(delim, start)) != string::npos){
            //no delim in the front
            ret.push_back(text.substr(start, (end-1) - (start-1) ));
            start = end + (int)delim.size();
        }
        if(start < text.size()) ret.push_back(text.substr(start));
    }

    unordered_map<int, vector<string>> set2syn;
    vector<string> ans;
    void backtrack(const vector<int>& text_i, int i, string cur){
        if(i==text_i.size()){
            ans.push_back( cur.substr(0, (int)cur.size()-1 ) );
            return;
        }

        for(const string& syn: set2syn[ set_find( text_i[i] ) ]){
            backtrack(text_i, i+1, cur + syn + " ");
        }
    }

    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        vector<string> text_split;
        split(text, text_split, " ");

        vector<int> text_i;
        for(const string& t: text_split){
            text_i.push_back( s2i(t) );
        }

        for(const vector<string>& syn: synonyms){
            s2i(syn[0]);
            s2i(syn[1]);
        }
        make_set(s2i_m.size());

        for(const vector<string>& syn: synonyms){
            set_join(s2i(syn[0]), s2i(syn[1]) );
        }

        for(const auto& [s, i]: s2i_m){
            set2syn[ set_find(i) ].push_back(s);
        }
        for(auto& [i, v]: set2syn){
            sort(v.begin(), v.end());
        }


        backtrack(text_i, 0, "");
        return ans;
    }
};