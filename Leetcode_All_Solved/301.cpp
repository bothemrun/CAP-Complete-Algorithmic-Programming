//backtracking O(2^parenthesis) = O(2^20) = O()1e6
//TODO: with ugly pruning.

#include<unordered_set>
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
    int n;
    string s;

    int min_cnt;

    unordered_set<int> removal;
    vector< unordered_set<int> > removal_vec;

    void backtrack_choose_or_not(const int& i, int left_paren){

        assert(left_paren >= 0);

        //pruning
        if((int)removal.size() > min_cnt) return;

        if(i == n){
            if(left_paren != 0) return;

            int cnt = removal.size();
            if(cnt == min_cnt){
                //NOTE: deep copy
                removal_vec.push_back(removal);
            }else if(cnt < min_cnt){
                removal_vec.clear();
                removal_vec.push_back(removal);

                min_cnt = cnt;
            }

            return;
        }


        const char& c = s[i];
        if(c == '('){

            //choose
            backtrack_choose_or_not(i+1, left_paren + 1);

            //not choose
            removal.insert(i);
            backtrack_choose_or_not(i+1, left_paren);
            removal.erase(i);

        }else if(c == ')'){

            if(left_paren == 0){
                //can't choose

                //not choose
                removal.insert(i);
                backtrack_choose_or_not(i+1, left_paren);
                removal.erase(i);
            }else{

                //choose
                backtrack_choose_or_not(i+1, left_paren - 1);

                //not choose
                removal.insert(i);
                backtrack_choose_or_not(i+1, left_paren);
                removal.erase(i);
            }

        }else{
            //alphabet, always choose
            backtrack_choose_or_not(i+1, left_paren);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();
        this->s = s;

        //TODO: ugly pruning
        bool has_right = false;
        for(int i=0;i<n;i++)if(s[i] == ')'){
            has_right = true;
            break;
        }
        if(has_right == false){
            string ans1 = "";
            for(int i=0;i<n;i++)if(s[i] != '('){
                ans1 += s[i];
            }
            return vector<string>({ans1});
        }

        min_cnt = n*2;

        backtrack_choose_or_not(0, 0);


        //optim: keep int while backtracking, not the whole substrings
        unordered_set<string> ans_set;
        for(const unordered_set<int>& re: removal_vec){
            string ans1 = "";

            for(int i=0;i<n;i++)if(re.count(i) == 0)
                ans1 += s[i];
            
            ans_set.insert(ans1);
        }

        vector<string> ans;
        for(const string& ans1: ans_set)
            ans.push_back(ans1);

        return ans;
    }
};
