//1. difference array.

//2. greedy, no one else can help / offline query:
//2.a. traverse positions from left to right. no one else can help this position to reduce nums[pos] to <= 0.
//2.b. so may need help from left_i <= pos.

//3. greedy by priority queue: intervals with the rightmost right_i are first.

//O(NlogQ)
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        auto cmp_sort = [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
            //don't care about r_i here
        };
        sort(queries.begin(), queries.end(), cmp_sort);
        
        int min_used = 0;
        vector<int> diff(n+3, 0);
        int sweep = 0;
        auto cmp_pq = [](const int& a, const int& b){
            //max heap for right
            return a<b;//max heap, sink down
        };
        priority_queue<int, vector<int>, decltype(cmp_pq)> maxheap(cmp_pq);
        int qi = (-1);
        int qn = queries.size();
        for(int pos=0;pos<n;pos++){
            while(qi+1 < qn && queries[qi+1][0] <= pos){
                qi++;
                maxheap.push( queries[qi][1] );
            }
            
            //ok for nums[pos] + old_sweep < 0!!
            sweep += diff[pos];
            int old_sweep = sweep;
            for(int k=0;k < nums[pos] + old_sweep;k++){
                //needs nums[pos] decrements!!
                if(maxheap.size() == 0){
                    return (-1);
                }
                min_used++;
                
                int right = maxheap.top();
                maxheap.pop();
                
                if(right < pos){
                    return (-1);
                }
                
                sweep--;
                //assert( right+1 < (int)diff.size() );
                diff[ right+1 ]++;
            }
        }
        return qn - min_used;
    }
};
