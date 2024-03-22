class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1, a2;
        a1.push_back(nums.at(0));
        a2.push_back(nums.at(1));

        int n = nums.size();
        for(int i=2;i<n;i++){
            if(a1.back() > a2.back()) a1.push_back(nums[i]);
            else a2.push_back(nums[i]);
        }

        for(const int& x: a2) a1.push_back(x);
        return a1;
    }
};
