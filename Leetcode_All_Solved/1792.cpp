typedef tuple<double, double> tdd;
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto cmp = [](const tdd& a, const tdd& b){
            const auto& [apass, atotal] = a;
            const auto& [bpass, btotal] = b;
            return (apass+1)/(atotal+1) - apass/atotal < (bpass+1)/(btotal+1) - bpass/btotal;
            //max heap in change, sink down
        };
        priority_queue<tdd, vector<tdd>, decltype(cmp)> maxheap(cmp);

        for(const auto& c: classes){
            maxheap.push(tdd(c[0], c[1]));
        }

        for(int i=0;i<extraStudents;i++){
            auto [pass, total] = maxheap.top();
            maxheap.pop();

            maxheap.push(tdd(pass+1, total+1));
        }

        double ans = 0;
        while(maxheap.size()){
            auto [pass, total] = maxheap.top();
            maxheap.pop();

            ans += pass / total;
        }
        return ans / (double)classes.size();
    }
};
