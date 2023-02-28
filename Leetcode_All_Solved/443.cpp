class Solution {
public:
    int compress(vector<char>& chars) {
        //NOTE: i <= start < end
        int n = chars.size();
        int i = 0;
        int start = 0, end = 1;
        while(start < n){
            while(end < n && chars[start] == chars[end]) end++;
            chars[i++] = chars[start]; //NOTE

            int len = (end-1) - (start-1);
            if(len >= 2){
                string len_s = to_string(len);
                for(const char& c: len_s) chars[i++] = c;
            }

            start = end;
            end = start + 1;
        }

        return i;
    }
};
