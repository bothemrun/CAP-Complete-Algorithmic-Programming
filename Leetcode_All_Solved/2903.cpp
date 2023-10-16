//O(n) by prefix min/max
#define PII pair<int,int>
#include<algorithm>
#include<utility>

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        vector<PII> prefix_mi(n);
        vector<PII> prefix_ma(n);
        prefix_mi.front() = PII(nums.front(), 0);
        prefix_ma.front() = PII(nums.front(), 0);

        auto cmp = [](const PII& a, const PII& b){
            return a.first < b.first;
        };
        for(int i=1;i<n;i++){
            prefix_mi[i] = min(
                prefix_mi[i-1],
                PII(nums[i], i),
                cmp
            );

            prefix_ma[i] = max(
                prefix_ma[i-1],
                PII(nums[i], i),
                cmp
            );
        }


        for(int i=indexDifference;i<n;i++){
            if(
                nums[i] - prefix_mi[i-indexDifference].first >= valueDifference
            ) return vector<int>({ i, prefix_mi[i-indexDifference].second });

            if(
                prefix_ma[i-indexDifference].first - nums[i] >= valueDifference
            ) return vector<int>({ i, prefix_ma[i-indexDifference].second });
        }

        return vector<int>({-1, -1});
    }
};
