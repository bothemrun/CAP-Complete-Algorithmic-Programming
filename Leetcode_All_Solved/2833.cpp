class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int any_dir = 0;
        int pos = 0;
        for(const char& c: moves){
            if(c == '_') any_dir++;
            else if(c == 'L') pos--;
            else pos++;
        }

        if(pos >= 0) return pos + any_dir;
        else return (-pos) + any_dir;
    }
};
