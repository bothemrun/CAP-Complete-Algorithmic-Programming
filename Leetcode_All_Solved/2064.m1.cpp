//m1
//regret greedy
//O( (n-m) log m ), extremely slow in 2400ms
#define tii tuple<int,int>
#define count(q, cnt) ( q/cnt + (q%cnt != 0) )
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto cmp = [](const tii& a, const tii& b){
            const auto& [quan_a, cnt_a] = a;
            const auto& [quan_b, cnt_b] = b;
            return count(quan_a, cnt_a) < count(quan_b, cnt_b);//max heap, sink down
            //if the quotients are the same,
            //don't have to further compare cnt_a & cnt_b.
            //tricky to prove. example:
            // 1/1 * 1 vs 2/2 * 2 --> 1/2 * 2 vs 2/3 * 3
            //eventually, they all have to go down to 1/2 * 2 plus 2/3 * 3
        };
        priority_queue<tii, vector<tii>, decltype(cmp)> maxheap(cmp);

        for(const int& q: quantities){
            maxheap.push(tii(q, 1));
        }

        int m = quantities.size();
        for(int t=0;t<n-m;t++){
            auto [q, cnt] = maxheap.top();
            maxheap.pop();

            maxheap.push(tii(q, cnt+1));
        }

        auto [q, cnt] = maxheap.top();
        return count(q, cnt);
    }
};
