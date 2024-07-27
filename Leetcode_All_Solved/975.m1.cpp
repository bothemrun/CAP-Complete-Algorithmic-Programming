//m1

//O(E) = O(V) = O(n)
//overall O(nlogn)

//[A] vector of bool:
//https://stackoverflow.com/questions/28882959/operator-on-stdvectorbool

//[B] must group the even & odd jumping in 1 for loop.

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
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> jump(n, vector<int>(2, false));
        jump.back()[0] = true;
        jump.back()[1] = true;

        multiset<tii> odd_ms;

        function<bool(const tii&, const tii&)> cmp = [](const tii& a, const tii& b){
            const auto& [av, ai] = a;
            const auto& [bv, bi] = b;
            if(av != bv) return av < bv;
            return ai > bi;//index decreasing
        };
        multiset<tii, decltype(cmp)> even_ms(cmp);

        for(int i=n-1;i>=0;i--){
            auto it1 = odd_ms.lower_bound(tii( arr[i], INT_MIN ));
            if(it1 != odd_ms.end()){
                const auto& [_, j] = *it1;
                jump[i][1] |= jump[j][0];
            }

            auto it2 = even_ms.upper_bound(tii( arr[i], INT_MIN ));
            if(it2 != even_ms.begin()){
                it2 = prev(it2);

                const auto& [_, j] = *it2;
                jump[i][0] |= jump[j][1];
            }

            //update
            odd_ms.insert(tii(arr[i], i));
            even_ms.insert(tii(arr[i], i));
        }


        int ans = 0;
        for(int i=0;i<n;i++) ans += jump[i][1];
        return ans;
    }
};
