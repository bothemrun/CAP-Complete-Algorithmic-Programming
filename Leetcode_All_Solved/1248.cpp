class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> odd2idx;
        for(int i=0;i<n;i++)if(nums[i]%2 == 1)
            odd2idx.push_back(i);
        int odd_cnt = odd2idx.size();

        if(!(k <= odd_cnt)) return 0;
        int low = k-1;

        odd2idx.push_back(n);//NOTE: dummy
        
        //[ odd2idx[low], odd2idx[low+1] )
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += (odd2idx.at(low+1) - 1) - (odd2idx.at(low) - 1);

            if(nums[i]%2 == 1){
                //update
                if(low+1 + 1 < odd2idx.size()) low++;
                else break;
            }
        }

        return cnt;
    }
};
