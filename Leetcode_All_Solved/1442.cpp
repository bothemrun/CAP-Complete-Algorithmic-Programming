class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix_xor = {arr[0]};
        for(int i=1;i<n;i++)prefix_xor.push_back(prefix_xor.back() ^ arr[i]);
        
        int ans = 0;
        for(int i=0;i<n-1;i++){
            for(int k=i+1;k<n;k++){
                for(int j=i+1;j<=k;j++){
                    //NOTE: xor is Abelian Group
                    //NOTE: A^0=A(identity) A^A=0(inverse) associative commutative
                    //NOTE: (A^B)^B=A^(B^B)=A^(0)=A : xor division
                    if( prefix_xor[j-1] ^ ( (i==0)?0:prefix_xor[i-1] ) == prefix_xor[k] ^ prefix_xor[j-1] )ans++;
                }
            }
        }
        return ans;
    }
};
