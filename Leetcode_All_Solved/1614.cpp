//O(n)

class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int stac = 0;
        for(const char& c: s){
            if(c == '('){
                max_depth = max(max_depth, ++stac);
            }else if(c == ')')
                assert(--stac >= 0);
        }

        return max_depth;
    }
};
