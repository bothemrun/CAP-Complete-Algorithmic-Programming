//m0
//1D sweep line by sorting, O(nlogn + mlogm)

#define PII pair<int,int>
#include<algorithm>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();

        vector<PII> sweep_line(2*m);
        for(int i=0;i<m;i++){
            sweep_line[2*i+1] = PII(flowers[i][1] + 1, -1);
            sweep_line[2*i] = PII(flowers[i][0], 1);
        }

        auto cmp = [](const PII& a, const PII& b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
            //(-1) end goes before 1 start
        };
        sort(sweep_line.begin(), sweep_line.end(), cmp);


        vector<PII> people2i(n);
        for(int i=0;i<n;i++)
            people2i[i] = PII(people[i], i);
        sort(people2i.begin(), people2i.end());


        vector<int> ans(n);
        int sweep = 0;
        int idx = 0;
        for(const auto& [pos, delta]: sweep_line){
            while(idx<n && people2i[idx].first < pos){
                ans[ people2i[idx++].second ] = sweep;
            }

            sweep += delta;
        }

        return ans;
    }
};
