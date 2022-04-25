class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        //NOTE: 1D Sweep Line. Leetcode 1893
        vector<int> cover(n, 0);//0-index
        for(const vector<int>& b:bookings){
            cover[b[0]-1] += b[2];
            if(b[1]-1 + 1<n) cover[b[1]-1 + 1] -= b[2];
        }
        
        for(int i=1;i<n;i++)cover[i] += cover[i-1];
        return cover;
    }
};
