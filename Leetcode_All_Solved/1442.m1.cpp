//m1
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix_xor = {arr[0]};
        for(int i=1;i<n;i++)prefix_xor.push_back(prefix_xor.back() ^ arr[i]);
        
        int ans = 0;
        for(int i=0;i<n-1;i++)
            for(int k=i+1;k<n;k++){
                //NOTE: precedence : usual ops(+-/ ++) > (==) > (^)
                //NOTE: use : xor is both multiplication & division
                if(arr[i] == (prefix_xor[k] ^ prefix_xor[i]) )ans += (k - i);
            }
        return ans;
    }
};
