class Solution {
public:
    int conse(vector<int>& bars){
        sort(bars.begin(), bars.end());
        
        int i=0;
        int n = bars.size();
        int max_con = 0;
        while(i<n){
            int j=i;
            while(j+1<n && bars[j] + 1 == bars[j+1] ){
                j++;
            }
            
            int len = j - (i-1);
            max_con = max(max_con, len);
            
            //update
            i = j+1;
        }
        return max_con;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h_max_con = conse(hBars);
        int v_max_con = conse(vBars);
        
        int side = min(h_max_con, v_max_con) + 1;
        return side * side;
    }
};
