class Solution {
public:
    int minimumSwap(string s1, string s2) {
        //NOTE: ignore same char pairs
        int xy = 0, yx = 0;
        for(int i=0;i<s1.size();i++)if(s1[i] != s2[i]){
            if(s1[i] == 'x') xy++;
            else yx++;
        }

        if( (xy + yx)%2 == 1)return (-1);

        return xy/2 + yx/2 + ( (yx%2==1)? 2:0 );
    }
};
