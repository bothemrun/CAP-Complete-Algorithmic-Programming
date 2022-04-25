#include<queue>
#include<utility>
#define GOODSIZE 3
#define SHIFT 1000
#define MAX_NUM 2000
class cmp_class{
public:
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
        return p1.first > p2.first;//min heap for last
        //doesn't matter for size (of undersize)
    }
};
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, cmp_class > minheap4undersize;//{last, size}
        vector<int> last4goodsize(MAX_NUM+1, 0);
        for(int x:nums){
            x += SHIFT;
            
            //NOTE: if(minheap4undersize.size() != 0){
            if(minheap4undersize.size() != 0 && minheap4undersize.top().first + 1 == x ){
                //prio 1: add to undersize w/ smallest last
                //NOTE: if(minheap4undersize.top().first + 1 != x)return false;//never achievable since non-increasing
                
                if(minheap4undersize.top().second+1 >= GOODSIZE){
                    minheap4undersize.pop();
                    last4goodsize.at(x)++;
                }else{
                    //minheap4undersize.top().second++;
                    pair<int,int> p = minheap4undersize.top();
                    minheap4undersize.pop();
                    minheap4undersize.push( {x, p.second+1} );
                }
            }else if(x != 0 && last4goodsize.at(x-1) > 0){
                //prio 2: add to legal existent
                last4goodsize.at(x-1)--;
                last4goodsize.at(x)++;
            }else{
                //prio 3: start a new subsequence
                minheap4undersize.push( {x, 1} );
            }
        }
        cout << "here\n";
        return minheap4undersize.size() == 0;
    }
};
