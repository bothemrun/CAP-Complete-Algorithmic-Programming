class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        //NOTE: 1D sweep line
        vector<int> sweep (length, 0);
        for(vector<int>& update:updates){
            sweep[update[0]] += update[2];
            if(update[1] + 1 < length) sweep[update[1] + 1] -= update[2];
        }
        
        vector<int> arr;
        int prefix_sum = 0;
        for(int& swe:sweep){
            prefix_sum += swe;
            arr.push_back(prefix_sum);
        }
        return arr;
    }
};
