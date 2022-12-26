class Solution {
public:
    vector<int> set;
    vector<int> set_cnt;

    int set_find(const int& a){
        if(set[a] == (-1))return a;
        return set[a] = set_find(set[a]);
    }

    inline void set_join(int a, int b){
        a = set_find(a);
        b = set_find(b);
        if(a != b){
            set[a] = b;//in case of a, b same tree, a is the root

            set_cnt[b] += set_cnt[a];
        }
    }

    vector<int> partitionLabels(string s) {
        vector<vector<int>> char2idx(26, vector<int>());
        for(int i=0;i<s.size();i++){
            char2idx[ (int)(s[i] - 'a') ].push_back(i);
        }

        set = vector<int>(s.size(), (-1));
        set_cnt = vector<int>(s.size(), 1);
        for(const vector<int>& idx: char2idx){
            if(idx.size() >= 2){
                for(int i=idx[0];i<=idx.back();i++)
                    set_join(i, idx[0]);
            }
        }

        vector<int> ans;
        for(int i=0;i<s.size();i++)if(set[i] == (-1)){
            ans.push_back(set_cnt[i]);
        }
        return ans;
    }
};




