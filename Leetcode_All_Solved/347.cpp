#define offset ((int)1e4)
#define maxsize (offset*2 + 3)
#include<queue>
#include<tuple>
class cmp_class{
public:
    bool operator()(const tuple<int,int>& a, const tuple<int,int>& b){
        return get<0>(a) < get<0>(b);//max heap, sink down
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cnt[maxsize] = {0};
        for(const int& num: nums) cnt[num + offset]++;

        priority_queue< tuple<int,int>, vector<tuple<int,int>>, cmp_class > maxheap;
        for(int num=-offset;num<=offset;num++)if(cnt[num + offset])
            maxheap.push( tuple<int,int>(cnt[num + offset], num) );
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(maxheap.size() == 0) break;

            ans.push_back( get<1>( maxheap.top() ) );
            maxheap.pop();
        }
        return ans;
    }
};
