//m1
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = (int)nums.size()/3;

        vector<long long> pre_min(3*n);
        vector<long long> suf_max(3*n);

        auto pre_cmp = [](const int& a, const int& b){
            return a<b;//max heap, sink down
        };
        auto suf_cmp = [](const int& a, const int& b){
            return a>b;//min heap, sink down
        };
        priority_queue<int, vector<int>, decltype(pre_cmp)> maxheap(pre_cmp);
        priority_queue<int, vector<int>, decltype(suf_cmp)> minheap(suf_cmp);
        long long pre_sum = 0;
        long long suf_sum = 0;

        auto push_pre = [&maxheap, &pre_sum, &nums](const int& i){
            maxheap.push(nums[i]);
            pre_sum += nums[i];
        };
        auto push_suf = [&minheap, &suf_sum, &nums](const int& i){
            minheap.push(nums[i]);
            suf_sum += nums[i];
        };
        auto pop_pre = [&maxheap, &pre_sum](){
            assert(maxheap.size());
            pre_sum -= maxheap.top();
            maxheap.pop();
        };
        auto pop_suf = [&minheap, &suf_sum](){
            assert(minheap.size());
            suf_sum -= minheap.top();
            minheap.pop();
        };


        for(int i=0;i<n-1;i++)
            push_pre(i);
        for(int i=0;i<n-1;i++)
            push_suf( (3*n-1) - i );
        
        for(int i=n-1;i<=2*n;i++){
            push_pre(i);

            if(maxheap.size() > n) pop_pre();

            pre_min[i] = pre_sum;
        }
        for(int i=2*n;i>=n;i--){
            push_suf(i);

            if(minheap.size() > n) pop_suf();

            suf_max[i] = suf_sum;
        }

        long long ans = LLONG_MAX;
        for(int i=n-1;i+n<3*n;i++){
            ans = min(
                ans,
                pre_min[i] - suf_max[i+1]
            );
        }
        return ans;
    }
};
