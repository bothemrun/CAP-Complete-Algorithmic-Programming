//O(n^2)
class Solution {
public:
    int shortestWay(string source, string target) {
        int m = source.size();
        int n = target.size();
        int cnt = 0;
        int i_tar = 0;
        while(i_tar < n){
            int i_src = 0;
            int old_i_tar = i_tar;
            while(i_src < m){
                if(target[i_tar] == source[i_src]){
                    i_tar++;
                    i_src++;
                }else i_src++;
            }

            if(old_i_tar == i_tar)return (-1);

            cnt++;
        }

        return cnt;
    }
};
