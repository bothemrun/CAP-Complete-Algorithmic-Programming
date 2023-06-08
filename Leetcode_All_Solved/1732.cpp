class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int altitude = 0;
        for(int i=0;i<gain.size();i++){
            altitude += gain.at(i);
            if(altitude > highest)
                highest = altitude;
        }
        return highest;
    }
};
