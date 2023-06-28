#define alphabet 26
#define c2i(c) ( c-'a' )
#define i2c(i) ( i+'a' )
#define mod(i) ( ( (i)%alphabet + alphabet) % alphabet )

#include<unordered_map>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int n = strings.size();

        unordered_map<string, vector<int>> trans2idxes;
        for(int i=0;i<n;i++){
            int front_i = c2i( strings[i].front() );

            string trans = "";
            for(const char& c: strings[i]){
                trans += i2c(
                    mod(
                        c2i(c) - front_i
                    )
                );
            }

            trans2idxes[trans].push_back(i);
        }

        vector<vector<string>> ans;
        for(const auto& [trans, idxes]: trans2idxes){

            vector<string> ans1;
            for(const int& idx: idxes)
                ans1.push_back( strings[idx] );
            
            ans.push_back(ans1);
        }

        return ans;
    }
};
