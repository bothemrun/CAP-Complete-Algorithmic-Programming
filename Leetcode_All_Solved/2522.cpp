#include<unordered_set>
#include<string>
class Solution {
public:
    int minimumPartition(string s, int k) {
        int cnt = 0;
        int low = 0;
        while(low < s.size()){
            unordered_set<char> digit;
            int i = low;//consider i, after i++: [low, i)
            while(i < s.size() && digit.count(s[i]) == 0 && stoll( s.substr(low, i - (low-1) ) ) <= k ){
                i++;
            }
            
            if(i == low){
                return (-1);//no i++
            }
            
            cnt++;
            low = i;
        }
        return cnt;
    }
};
