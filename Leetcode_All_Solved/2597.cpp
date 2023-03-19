#include<unordered_set>
class Solution {
public:
    int cnt = 0;
    vector<bool> uset;
    bool count(const int& a){
        if( !(1 <= a && a <= 1000) )return false;
        return uset[a];
    }
    inline void insert(const int& a){
        uset[a] = true;
    }
    inline void erase(const int& a){
        uset[a] = false;
    }
    //void subset(const vector<int>& nums, const int& k, const int& i, unordered_set<int>& uset){
    void subset(const vector<int>& nums, const int& k, const int& i){
        if(i == nums.size()){
            cnt++;
            return;
        }
        
        subset(nums, k, i+1); //, uset);
        
        //if(uset.count(nums[i] - k) == 0 && uset.count(nums[i] + k) == 0){
        if(count(nums[i] - k) == 0 && count(nums[i] + k) == 0){
            //uset.insert(nums[i]);
            insert(nums[i]);
            subset(nums, k, i+1); //, uset);
            //uset.erase(nums[i]);
            erase(nums[i]);
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        //unordered_set<int> uset;
        uset = vector<bool>(1002, false);
        subset(nums, k, 0);// , uset);
        return cnt - 1;//non-empty
    }
};
