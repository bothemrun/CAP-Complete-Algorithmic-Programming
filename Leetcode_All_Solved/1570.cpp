class SparseVector {
public:
    vector<vector<int>> sparse;
    
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++)if(nums[i] != 0)
            this->sparse.push_back( vector<int>( {i, nums[i]} ) );
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        int i = 0, j = 0;
        while(i < this->sparse.size() && j < vec.sparse.size()){
            int idx1 = this->sparse[i].front();
            int idx2 = vec.sparse[j].front();
            if(idx1 == idx2)
                res += this->sparse[i++].back() * vec.sparse[j++].back();
            else if(idx1 < idx2) i++;
            else j++;
        }

        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
