//m1

//coordinate discretization + 2D diff array

//O(n^2)
#define mod ((long long)1e9 + 7LL)

class Solution {
public:
    vector<vector<int>> diff;
    vector<vector<int>> cover;
    int m, n;
    inline void init(int m, int n){
        this->m = m;
        this->n = n;
        //must size + 1
        diff.resize(m + 1, vector<int>(n + 1, 0));
    }
    inline void range_update(int x1, int y1, int x2, int y2, int val){
        diff[x1][y1] += val;

        diff[x1][y2+1] -= val;
        diff[x2+1][y1] -= val;

        diff[x2+1][y2+1] += val;
    }
    inline int coor(int i, int j){
        if(i>=0 && j>=0) return cover[i][j];
        else return 0;
    }
    inline void compute_diff(){
        cover.resize(m, vector<int>(n));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                cover[i][j] = (
                    diff[i][j]
                    - coor(i-1, j-1)
                    + coor(i-1, j)
                    + coor(i, j-1)
                );
            }
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        unordered_set<int> uni_x, uni_y;
        for(const vector<int>& r: rectangles){
            uni_x.insert(r[0]);
            uni_y.insert(r[1]);

            uni_x.insert(r[2]);
            uni_y.insert(r[3]);
        }

        vector<int> dis_x, dis_y;
        for(const int& x: uni_x) dis_x.push_back(x);
        for(const int& y: uni_y) dis_y.push_back(y);
        sort(dis_x.begin(), dis_x.end());
        sort(dis_y.begin(), dis_y.end());

        //dis_x & x_dis are inverse maps.
        unordered_map<int, int> x_dis, y_dis;
        for(int i=0;i<dis_x.size();i++)
            x_dis[ dis_x[i] ] = i;
        for(int j=0;j<dis_y.size();j++)
            y_dis[ dis_y[j] ] = j;


        init(dis_x.size(), dis_y.size());

        for(const vector<int>& r: rectangles){
            range_update(
                x_dis[r[0]],
                y_dis[r[1]],

                //x_dis[r[2]],
                //y_dis[r[3]],
                x_dis[r[2]] - 1,
                y_dis[r[3]] - 1,


                1
            );
        }

        compute_diff();

        long long area = 0;
        for(int i=0;i+1<m;i++)
            for(int j=0;j+1<n;j++)if(cover[i][j] > 0){
                area = (
                    area +
                    (long long)( dis_x[i+1] - dis_x[i] ) *
                    (long long)( dis_y[j+1] - dis_y[j] )
                )%mod;
            }
        return area;
    }
};
