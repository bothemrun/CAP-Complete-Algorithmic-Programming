class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        int n = goal.size();
        if(m != n) return false;

        for(int start=0;start<m;start++){
            bool good = true;
            for(int i=0;i<m;i++)if( s[ (start+i)%m ] != goal[i] ){
                good = false;
                break;
            }
            if(good) return true;
        }
        return false;
    }
};
