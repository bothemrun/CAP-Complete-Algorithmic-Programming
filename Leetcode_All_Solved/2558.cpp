#include<math.h>
#include<queue>

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        auto cmp = [](const int& a, const int& b){
            return a<b;//max heap
        };
        priority_queue<int, vector<int>, decltype(cmp) > maxheap(cmp);

        for(const int& g: gifts) maxheap.push(g);

        for(int i=0;i<k;i++){
            if(maxheap.size() == 0) break;
            int g = maxheap.top();
            maxheap.pop();

            int g2 = (int)sqrt(g);
            if(g2 != 0) maxheap.push(g2);
        }

        long long ans = 0;
        while(maxheap.size()){
            ans += maxheap.top();
            maxheap.pop();
        }

        return ans;
    }
};
