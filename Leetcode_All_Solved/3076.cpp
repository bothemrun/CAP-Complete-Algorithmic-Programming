//L := arr.length <= 20,
//O(n * L^2) = O(1e2 * 4e2) = O(4e4) for building the hash maps.
//for brute force, due to making the substrings, actually O(n * L^3) = O(6e5)

//pure brute force: O(n * L^2 * count of all substrings) 
//= O(n * L^2 * n*L^2) = O((4e4)^2) = O(1.6e9)

#include<unordered_map>

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string, int> sub2cnt;
        vector<unordered_map<string, int>> self_sub2cnt(n);

        for(int t=0;t<n;t++){
            const string& s = arr[t];
            int l = s.size();

            for(int i=0;i<l;i++){
                string sub = "";

                for(int j=i;j<l;j++){
                    sub += s[j];

                    sub2cnt[sub]++;

                    self_sub2cnt[t][sub]++;
                }
            }
        }

        vector<string> ans(n, "");
        for(int t=0;t<n;t++){
            const string& s = arr[t];
            int l = s.size();

            bool found = false;

            for(int len=1;len<=l;len++){
                for(int i=0;i+(len-1)<l;i++){
                    string sub = s.substr(i, len);
                    if( sub2cnt[sub] - self_sub2cnt[t][sub] == 0 ){
                        found = true;

                        if(ans[t] == ""){
                            ans[t] = sub;
                        }else{
                            ans[t] = min(ans[t], sub);
                        }
                    }
                }

                if(found) break;
            }
        }

        return ans;
    }
};
