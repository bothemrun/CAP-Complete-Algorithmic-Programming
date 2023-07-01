//m0

//backtracking enumeration in O(k^n) = = O(8^8) 1.7*10^7 will work.

//but won't work in 1723. Find Minimum Time to Finish All Jobs,
//which needs O(12^12).

//NOTE: pruning:
//1. the case that some child has no cookies is the worst due to k <= n.
//so when there are less bags to dispatch to the remaining children, we prune this branch.

//2. early stopping: keep a global answer for early stopping.

#include<limits.h>
#include<algorithm>

class Solution {
public:
    int min_ans = INT_MAX;
    int n, k;

    void backtrack(const vector<int>& cookies, vector<int>& cnt, const int& i, const int& cur_max, const int& children0cookie){
        if(i==n){
            min_ans = min(min_ans, cur_max);
            return;
        }

        //NOTE: pruning
        if(children0cookie > n-i) return;
        if(cur_max >= min_ans) return;

        for(int child=0;child<k;child++){
            bool no_cookie = cnt[child] == 0;

            cnt[child] += cookies[i];
            backtrack(cookies, cnt, i+1, max(cur_max, cnt[child]), children0cookie - no_cookie );
            cnt[child] -= cookies[i];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        this->n = cookies.size();
        this->k = k;

        vector<int> cnt(k, 0);

        backtrack(cookies, cnt, 0, 0, 0);
        return min_ans;
    }
};
