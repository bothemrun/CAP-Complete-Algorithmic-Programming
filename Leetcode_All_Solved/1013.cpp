//NOTE: generalized for k partition with equal sum.
#define part 3
class Solution {
public:
    int n;

    bool k_partition(const vector<int>& arr, const int& target, int k, int start=0){
        if(!(start < n))return false;
        if(k == 1)return true;

        int sum = 0;
        for(int i=start;i<n;i++){
            sum += arr[i];

            if(sum == target){
                if( k_partition(arr, target, k-1, i+1) == true)
                    return true;
            }
        }

        return false;
    }

    bool canThreePartsEqualSum(vector<int>& arr) {
        n = arr.size();
        int sum = 0;//NOTE: no overflow
        for(int i=0;i<n;i++) sum += arr[i];

        if(sum%part != 0)return false;

        int target = sum/part;

        return k_partition(arr, target, part);
    }
};
