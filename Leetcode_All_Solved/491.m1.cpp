//m1
//unordered_set of vectors by custom hasher

//NOTE: C++ stl has set/map of vectors

//https://www.geeksforgeeks.org/set-of-vectors-in-c-stl-with-examples/

//https://www.geeksforgeeks.org/map-of-vectors-in-c-stl-with-examples/

//while unordered_set of vectors need customized hasher.
//https://www.geeksforgeeks.org/unordered-set-of-vectors-in-c-with-examples/

#define set_type 1 //0 1

#include<set>

#if set_type == 1
#include<functional>
class hash_class{
public:
    size_t operator()(const vector<int>& v) const {
        hash<int> hasher;
        size_t ans = 0;//Identity for xor
        for(const int& i: v){
            //ans ^= hasher(i);

            //NOTE: https://www.geeksforgeeks.org/unordered-set-of-vectors-in-c-with-examples/

            ans ^= hasher(i) + 0x9e3779b9 + 
                (ans << 6) + (ans >> 2);
        }
        return ans;
    }
};
#endif

class Solution {
public:

#if set_type == 0
    inline void insert(vector<vector<int>>& dp_end_i, set<vector<int>>& setv, const vector<int>& v){
        dp_end_i.push_back(v);
        setv.insert(v);
    }
#else
    inline void insert(vector<vector<int>>& dp_end_i, unordered_set<vector<int>, hash_class>& usetv, const vector<int>& v){
        dp_end_i.push_back(v);
        usetv.insert(v);
    }
#endif

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp_end( n, vector<vector<int>>() );

        //NOTE: set of vectors by stl
        #if set_type == 0
        set<vector<int>> setv;
        #else
        unordered_set<vector<int>, hash_class> usetv;
        #endif

        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)if(nums[j] <= nums[i]){
                for(vector<int> v: dp_end[j]){
                    v.push_back(nums[i]);

                    #if set_type == 0
                    if(setv.count(v) == 0)
                        insert(dp_end[i], setv, v);
                    #else
                    if(usetv.count(v) == 0)
                        insert(dp_end[i], usetv, v);
                    #endif
                        
                }

                vector<int> v = {nums[j], nums[i]};

                #if set_type == 0
                if(setv.count(v) == 0)
                    insert(dp_end[i], setv, v);
                #else
                if(usetv.count(v) == 0)
                    insert(dp_end[i], usetv, v);
                #endif
            }
        
        vector<vector<int>> ans;
        for(int i=1;i<n;i++)
            for(const vector<int>& v: dp_end[i])
                ans.push_back(v);
        return ans;
    }
};
