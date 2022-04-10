class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //NOTE: xor: A^0=A (identity) A^A=0 (inverse) associative, so (B^A)^A = B^(A^A) = B^(0) = B : the division of xor
        //NOTE: xor is an Abelian Group. 
        vector<int> prefix_product = {arr[0]};
        for(int i=1;i<arr.size();i++) prefix_product.push_back( prefix_product.back() ^ arr[i] );
        
        vector<int> ans;
        for(const vector<int>& q:queries){
            int left = q[0], right = q[1];
            if(left == 0)ans.push_back(prefix_product[right]);
            else ans.push_back( prefix_product[right] ^ prefix_product[left-1] );
        }
        return ans;
    }
};
