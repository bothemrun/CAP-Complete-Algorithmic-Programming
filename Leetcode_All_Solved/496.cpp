#include<unordered_map>
#include<stack>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> monosta;
        unordered_map<int, int> val2ans;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            while(monosta.size() != 0 && nums2[i] >= monosta.top()){
                monosta.pop();
            }

            if(monosta.size() == 0) val2ans[nums2[i]] = (-1);
            else val2ans[nums2[i]] = monosta.top();

            monosta.push(nums2[i]);
        }

        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++)
            ans[i] = val2ans[nums1[i]];
        return ans;
    }
};
