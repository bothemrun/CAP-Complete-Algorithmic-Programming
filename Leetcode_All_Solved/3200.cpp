class Solution {
public:
    inline int tri(int a, int b){
        for(int i=1;;i++){
            if(i%2==0){
                if(a-i < 0) return i-1;

                a -= i;
            }else{
                if(b-i < 0) return i-1;

                b -= i;
            }
        }

        assert(false);
        return (-1);
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(
            tri(red, blue),
            tri(blue, red)
        );
    }
};
