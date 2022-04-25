//since same as Leetcode 1296. Divide Array in Sets of K Consecutive Numbers
#define nums hand
#define k groupSize
#include<algorithm>
#include<queue>
#include<utility>
class cmp_class{
public:
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
        return p1.first > p2.first;//min heap for last number
    }
};
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(k == 1)return true;
        if(nums.size()%k != 0)return false;
        
        sort(nums.begin(), nums.end());
        priority_queue< pair<int,int>, vector<pair<int,int>>, cmp_class > minheap4last;
        //only keep track of undersize
        for(const int& x:nums){
            if(minheap4last.size() == 0)minheap4last.push({x, 1});
            else if(minheap4last.top().first + 1 == x){
                //or else never achievable since non-decreasing
                pair<int,int> p = minheap4last.top();
                minheap4last.pop();
                if(p.second + 1 < k) minheap4last.push( {x, p.second+1} );
            }else{
                minheap4last.push( {x, 1} );
            }
        }
        return minheap4last.size() == 0;
    }
};
