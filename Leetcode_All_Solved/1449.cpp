//m0
//[A] Unbounded Knapsack O(nW) = O(9*target)

//[B] but int overflow
//1. so use string to represent integers

#include<functional>

class Solution {
public:
    const string notyet = "-1";
    vector<string> memo;
    const int n = 9;

    const string impossible = "-2";
    const string end = "0";

    function<bool(const string&, const string&)> cmp = [&impossible = impossible](const string& a, const string& b){
        if(a==impossible) return true;
        if(b==impossible) return false;

        if(a.size() != b.size()) return a.size() < b.size();
        return a<b;
    };

    string unbounded_knapsack(const vector<int>& cost, int sum){
        if(sum==0) return end;

        if(sum < 0) return impossible;

        if(memo[sum] != notyet) return memo[sum];

        string ret = impossible;
        for(int d=1;d<=n;d++){
            string sub = unbounded_knapsack(cost, sum - cost[d-1]);
            if(sub == impossible) continue;

            if(sub == end)
                ret = max(
                    ret,
                    to_string(d),
                    cmp
                );
            else
                ret = max(
                    ret,
                    sub + to_string(d),
                    cmp
                );
        }
        return memo[sum] = ret;
    }

    string largestNumber(vector<int>& cost, int target) {
        memo.resize(target + 1, notyet);

        string ret = unbounded_knapsack(cost, target);
        if(ret == impossible) return "0";
        return ret;
    }
};
