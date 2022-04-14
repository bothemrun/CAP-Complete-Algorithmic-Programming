#include<unordered_set>
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int dup = (-1);
        for(const int& x:nums){
            if(s.count(x) != 0) dup = x;
            s.insert(x);
        }
        for(int i=1;i<=nums.size();i++){
            if(s.count(i) == 0)return vector<int>({dup, i});
        }
        return vector<int>({-2,-4});//not here
    }
};
