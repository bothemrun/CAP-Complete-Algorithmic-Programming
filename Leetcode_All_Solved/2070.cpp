//m0
//offline query
//O(QlogQ + NlogN)

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int qn = queries.size();

        vector<int> queries_idx(qn);
        for(int i=0;i<qn;i++) queries_idx[i] = i;

        auto cmp = [&queries](const int& i, const int& j){
            return queries[i] < queries[j];
        };
        sort(queries_idx.begin(), queries_idx.end(), cmp);

        sort(items.begin(), items.end());


        vector<int> ans(qn);
        int i = (-1);//index of items
        int pref_max = 0;//ok for not found

        for(const int& qi: queries_idx){
            const int& q = queries[qi];

            while(i+1<n && items[i+1][0] <= q){
                i++;
                pref_max = max(pref_max, items[i][1]);
            }

            ans[qi] = pref_max;
        }
        return ans;
    }
};
