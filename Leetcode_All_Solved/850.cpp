//m0

//coordinate discretization + brute force(TLE without discretization)
//O(n^2)

#define mod ((long long)1e9 + 7LL)
#include<functional>

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        //coordinate discretization
        unordered_set<int> uni_x, uni_y;
        for(const vector<int>& r: rectangles){
            uni_x.insert(r[0]);
            uni_y.insert(r[1]);

            uni_x.insert(r[2]);
            uni_y.insert(r[3]);
        }

        vector<int> dis_x;
        vector<int> dis_y;
        for(const int& x: uni_x) dis_x.push_back(x);
        for(const int& y: uni_y) dis_y.push_back(y);

        sort(dis_x.begin(), dis_x.end());
        sort(dis_y.begin(), dis_y.end());


        //paint the compressed coordinate sysmte
        vector<vector<bool>> covered(dis_x.size(), vector<bool>(dis_y.size(), false) );

        function<int(int, const vector<int>&)> to_discrete = [](int x, const vector<int>& dis_x){
            return lower_bound(
                dis_x.begin(),
                dis_x.end(),
                x
            ) - dis_x.begin();
        };

        //this actually O(n^3)
        for(const vector<int>& r: rectangles){
            //use original coordinates to find discretized coordinates by binary search
            int dis_x1 = to_discrete(r[0], dis_x);
            int dis_y1 = to_discrete(r[1], dis_y);

            int dis_x2 = to_discrete(r[2], dis_x);
            int dis_y2 = to_discrete(r[3], dis_y);

            for(int i=dis_x1;i<dis_x2;i++)
                for(int j=dis_y1;j<dis_y2;j++){
                    covered[i][j] = true;
                }
        }

        
        long long area = 0;
        for(int i=0;i+1<dis_x.size();i++)
            for(int j=0;j+1<dis_y.size();j++)if(covered[i][j] == true){
                area = (
                    area +
                    (long long)( dis_x[i+1] - dis_x[i] ) *
                    (long long)( dis_y[j+1] - dis_y[j] ) % mod
                )%mod;
            }
        return area;
    }
};
