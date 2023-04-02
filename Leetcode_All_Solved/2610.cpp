#define max_num 200
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> num2cnt(max_num + 1, 0);
        for(const int& num: nums){
            num2cnt[num]++;
        }
        
        vector<vector<int>> ans;
        while(true){
            vector<int> row;
            bool has1 = false;
            for(int i=1;i<=max_num;i++)if(num2cnt[i] > 0){
                row.push_back(i);
                num2cnt[i]--;
                has1 = true;
            }
            if(has1 == false){
                break;
            }
            ans.push_back(row);
        }
        return ans;
    }
};
