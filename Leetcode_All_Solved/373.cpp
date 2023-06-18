//NOTE: deduplicate by encoding 2 indices to a string
//NOTE: waste time & space by copying values to the priority queue
#define concat "$"
#define encode(a, b) ( to_string(a) + concat + to_string(b) )
#include<queue>
#include<unordered_set>
#include<string>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class cmp_class{
public:
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[0]+a[1] > b[0]+b[1];
        //min heap in sums, sink down
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> ans;

        priority_queue<vector<int>, vector<vector<int>>, cmp_class> minheap;
        minheap.push(vector<int>({
            nums1[0], nums2[0], 0, 0
        }));

        unordered_set<string> uset;
        uset.insert(encode(0, 0));

        for(int l=0;l<k;l++){
            if(minheap.size() == 0) break;

            //NOTE: can't use reference or const reference!
            vector<int> v = minheap.top();
            minheap.pop();

            ans.push_back( vector<int>({v[0], v[1]}) );

            if(v[2]+1<m && uset.count(encode(v[2]+1, v[3])) == 0){
                int x = v[2]+1, y = v[3];
                uset.insert(encode(x, y));
                minheap.push( vector<int>({
                    nums1[x], nums2[y], x, y
                }) );
            }
            if(v[3]+1<n && uset.count(encode(v[2], v[3]+1)) == 0){
                int x = v[2], y = v[3]+1;
                uset.insert(encode(x, y));
                minheap.push( vector<int>({
                    nums1[x], nums2[y], x, y
                }) );
            }
        }

        return ans;
    }
};
