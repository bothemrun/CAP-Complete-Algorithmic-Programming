//m1

//NOTE: not to copy values to heap:
//NOTE: use lambda expression with decltype for the pq, variable capture by reference.

//NOTE: de-duplicate:
//NOTE: use a set of pairs (since unordered_set needs custom comparators),
//NOTE: still introduces the same time complexity.

#include<queue>
#include<set>
#include<utility>
#include<iostream>
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        //NOTE: use lambda expression with decltype for the pq, variable capture by reference.
        auto cmp_lam = [&nums1, &nums2](const pair<int,int>& a, const pair<int,int>& b){
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];//min heap, sink down
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp_lam) > minheap(cmp_lam);

        set<pair<int,int>> dedup;

        minheap.push(pair<int,int>(0, 0));
        dedup.insert(pair<int,int>(0, 0));

        vector<vector<int>> ans;
        for(int l=0;l<k;l++){
            if(minheap.size() == 0) break;

            //can't use (const) reference
            auto [i, j] = minheap.top();
            minheap.pop();

            ans.push_back(vector<int>({nums1[i], nums2[j] }));

            if(i+1<m){
                pair<int,int> tmp(i+1, j);
                if(dedup.count(tmp) == 0){
                    minheap.push(tmp);
                    dedup.insert(tmp);
                }
            }
            if(j+1<n){
                pair<int,int> tmp(i, j+1);
                if(dedup.count(tmp) == 0){
                    minheap.push(tmp);
                    dedup.insert(tmp);
                }
            }
        }

        return ans;
    }
};
