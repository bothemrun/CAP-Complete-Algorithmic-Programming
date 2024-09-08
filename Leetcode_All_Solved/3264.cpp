//O(klogn)
#define tii tuple<int,int>
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        function<bool(const tii&, const tii&)> cmp = [](const tii& a, const tii& b){
            const auto& [av, ai] = a;
            const auto& [bv, bi] = b;
            if(av != bv) return av < bv;
            return ai < bi;
        };
        multiset<tii, decltype(cmp)> ms(cmp);

        for(int i=0;i<(int)nums.size();i++){
            ms.insert(tii(nums[i], i));
        }

        for(int t=0;t<k;t++){
            auto [v, i] = *ms.begin();
            //v *= multiplier;

            //ms.erase(val) erases all instances
            ms.erase(ms.begin());
            ms.insert(tii(v * multiplier, i));
        }

        for(const auto& [v, i]: ms){
            nums[i] = v;
        }
        return nums;
    }
};
