class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i=0;i<nums.size();){
            int j;
            for(j=i+1;j<nums.size();j++){
                if(nums.at(i) != nums.at(j)) break;
            }
            nums.at(k++) = nums.at(i);
            i = j;
        }
        return k;
    }
};
