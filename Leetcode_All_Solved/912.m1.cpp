//m1
//optim from m0 wrong divide & conquer,
//using only 1 tmp vector globally
class Solution {
public:
    void divide_conquer(vector<int>& nums, const int& low, const int& high, vector<int>& tmp1){
        if(low == high)return;

        int mid = (high-low)/2 + low;
        divide_conquer(nums, low, mid, tmp1);
        divide_conquer(nums, mid+1, high, tmp1);

        for(int i=low;i<=high;i++)
            tmp1[i] = nums[i];
        int i = low, j = mid+1;
        int k = low;
        while(i<=mid && j<=high){
            if(tmp1[i] < tmp1[j])
                nums[k++] = tmp1[i++];
            else nums[k++] = tmp1[j++];
        }
        while(i<=mid) nums[k++] = tmp1[i++];
        while(j<=high) nums[k++] = tmp1[j++];
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp1(n);
        divide_conquer(nums, 0, n-1, tmp1);
        return nums;
    }
};
