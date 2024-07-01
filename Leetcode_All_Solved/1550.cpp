#define par(x) (x%2==1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i+2<n;i++)
            if( par(arr[i]) && par(arr[i+1]) && par(arr[i+2]) )
                return true;
        return false;
    }
};
