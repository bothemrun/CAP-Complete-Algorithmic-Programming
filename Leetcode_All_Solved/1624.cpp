#include<algorithm>
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        const int alpha = 26;
        const int no_occur = (-1);
        vector<int> first(alpha, no_occur);
        vector<int> last(alpha, no_occur);

        int n = s.size();
        for(int i=0;i<n;i++){
            if(first[ s[i] - 'a' ] == no_occur)
                first[ s[i] - 'a' ] = i;
            
            last[ s[i] - 'a' ] = i;
        }

        int ans = (-1);
        for(int i=0;i<alpha;i++){
            if( first[i] == no_occur ) continue;

            ans = max(
                ans,
                last[i] - first[i] - 1
            );
        }
        return ans;
    }
};
