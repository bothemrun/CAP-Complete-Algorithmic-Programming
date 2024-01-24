//m0
//O(n)

//[A] group cases
//1. 4 cases: 3 concatenated cases, 1 self group (obvious)

//2. (concat case 1)
//2.1. 1 group extended by 1 char

//3. (concat case 2)
//3.1. 2 groups concatenated by:

//3.a. another extra char not belonging to these 2 groups

//3.b. the 2nd group's last char concatenating these 2 groups.


//[B] preprocessing
//1. preprocessing: run-length encoding

#define tu2 tuple<char, int>
#include<tuple>
#include<algorithm>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxRepOpt1(string text) {
        int m = text.size();

        //run-length encoding
        vector<tu2> run_len;

        int cnt[256] = {0};

        int start=0;
        while(start<m){
            int end = start;
            while(end+1<m && text[start] == text[end+1]){
                end++;
            }

            run_len.push_back( tu2( text[start], end - (start-1) ) );

            cnt[text[start]] += end - (start-1);

            //update
            start = end+1;
        }


        int n = run_len.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            //structured binding declaration in C++
            //like destructuring assignment in Javascript
            const auto& [c, l] = run_len[i];

            //case 1.
            ans = max(ans, l);

            //case 2.
            if(cnt[c] > l) ans = max(ans, l+1);

            //case 3 & 4
            if(i+2<n){
                const auto& [c1, l1] = run_len[i+1];
                const auto& [c2, l2] = run_len[i+2];
                if(c == c2 && l1 == 1){
                    if(cnt[c] == l + l2)
                        ans = max(ans, l + l2);
                    else
                        ans = max(ans, l + l2 + 1);
                }
            }
        }

        return ans;
    }
};
