#include<algorithm>
#include<unordered_map>
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int max_cnt = 0;
        unordered_map<int,int> type2cnt;
        
        int high = 0;
        //NOTE: [low, high), consider high in while loop
        for(int low=0;low<n;low++){
            while(high < n && 
            ( type2cnt.size() <= 1 || type2cnt.count(fruits[high]) != 0 ) 
            ){
                if( type2cnt.count(fruits[high]) == 0)
                    type2cnt[fruits[high]] = 1;
                else type2cnt[fruits[high]]++;

                high++;
            }

            max_cnt = max(max_cnt, (high-1) - (low-1) );

            //update
            if( --type2cnt[fruits[low]] == 0)
                type2cnt.erase(fruits[low]);
        }

        return max_cnt;
    }
};
