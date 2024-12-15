class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int ans = (-1);
        auto check = [&](int i, int j, int k, int l, int idx){
            vector<int> p = { points[i][idx], points[j][idx], points[k][idx], points[l][idx] };
            sort(p.begin(), p.end());
            //can't use a single line
            if( p[0]==p[1] && p[1] != p[2] && p[2]==p[3] ){
                return true;
            }
            return false;
        };
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        if( check(i, j, k, l, 0)==false || check(i, j, k, l, 1)==false ){
                            continue;
                        }
                        
                        vector<int> x = { points[i][0], points[j][0], points[k][0], points[l][0] };
                        vector<int> y = { points[i][1], points[j][1], points[k][1], points[l][1] };
                        int min_x = *min_element(x.begin(), x.end());
                        int max_x = *max_element(x.begin(), x.end());
                        int min_y = *min_element(y.begin(), y.end());
                        int max_y = *max_element(y.begin(), y.end());
                        bool good = true;
                        for(int a=0;a<n;a++){
                            if(a==i || a==j || a==k || a==l){
                                continue;
                            }
                            int ax = points[a][0];
                            int ay = points[a][1];
                            if(min_x <= ax && ax <= max_x && min_y <= ay && ay <= max_y){
                                good = false;
                                break;
                            }
                        }
                        if(good==true){
                            ans = max(ans, (max_x - min_x) * (max_y - min_y) );
                        }
                    }
                }
            }
        }
        return ans;
    }
};
