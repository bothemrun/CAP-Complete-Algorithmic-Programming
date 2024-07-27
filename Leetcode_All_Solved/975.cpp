//m0

//O(nlogn)
//O(edges) = O(n), not O(n^2)
#define tii tuple<int,int>
#include<functional>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<vector<int>>> al;

    int n;
    const int notyet = (-1);
    vector<vector<int>> memo;

    bool dfs(int u, int step){
        if(u == n-1) return true;

        if(memo[u][step] != notyet) return memo[u][step];

        bool ret = false;
        for(const int& v: al[u][step]){
            ret |= dfs(v, (step+1)%2);
        }
        return memo[u][step] = ret;
    }

    int oddEvenJumps(vector<int>& arr) {
        this->n = arr.size();
        al.resize(n, vector<vector<int>>(2));

        //odd suffix multiset
        multiset<tii> odd_ms;
        for(int i=n-1;i>=0;i--){
            auto it = odd_ms.lower_bound(tii( arr[i], INT_MIN ));

            if(it != odd_ms.end()){
                const auto& [_, j] = *it;
                al[i][1].push_back(j);
            }

            //update
            odd_ms.insert(tii(arr[i], i));
        }

        //even suffix multiset
        //can also use tuple: (arr[i], -i)
        auto cmp = [](const tii& a, const tii& b){
            const auto& [av, ai] = a;
            const auto& [bv, bi] = b;
            if(av != bv) return av < bv;
            return ai > bi;//indices decreasing
        };
        multiset<tii, decltype(cmp)> even_ms(cmp);
        for(int i=n-1;i>=0;i--){
            //auto it = even_ms.upper_bound(tii( arr[i], INT_MAX ));
            auto it = even_ms.upper_bound(tii( arr[i], INT_MIN ));

            if(it != even_ms.begin()){
                it = prev(it);

                const auto& [_, j] = *it;
                al[i][0].push_back(j);
            }

            //update
            even_ms.insert(tii(arr[i], i));
        }


        memo.resize(n, vector<int>(2, notyet));
        int ans = 0;
        for(int i=0;i<n;i++)
            ans += dfs(i, 1);
        return ans;
    }
};
