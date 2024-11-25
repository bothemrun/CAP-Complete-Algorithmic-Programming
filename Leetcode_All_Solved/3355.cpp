//m0
//O(nlogn) line sweep. 
//(can be improved by difference array in O(n))

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

#define tii tuple<int,int>
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int qn = queries.size();
        vector<tii> line_sweep;
        for(const vector<int>& q: queries){
            line_sweep.push_back(tii( q[0], -1 ));
            line_sweep.push_back(tii( q[1]+1, 1 ));
        }
        auto cmp = [](const tii& a, const tii& b){
            const auto& [apos, ad] = a;
            const auto& [bpos, bd] = b;
            if(apos != bpos) return apos < bpos;
            return ad > bd;
        };
        //for the same positions, 1 before -1
        sort(line_sweep.begin(), line_sweep.end(), cmp);
        
        int sweep = 0;
        int last_pos = (-1);
        for(const auto& [pos, delta]: line_sweep){
            int old_sweep = sweep;
            sweep += delta;
            assert(sweep <= 0);
            if(last_pos != (-1) && old_sweep < 0){
                for(int i=last_pos;i<pos;i++){
                    nums[i] += old_sweep;
                }
            }
            
            last_pos = pos;
        }
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                return false;
            }
        }
        return true;
    }
};
