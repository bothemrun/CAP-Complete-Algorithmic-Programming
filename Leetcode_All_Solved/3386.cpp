class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int max_time = 0;
        int min_index = 0;
        int last_time = 0;
        for(const auto& e: events){
            const int index = e[0];
            const int time = e[1];
            const int delta = time - last_time;
            if(delta > max_time){
                max_time = delta;
                min_index = index;
            }else if(delta == max_time && index < min_index){
                min_index = index;
            }
            
            //update
            last_time = time;
        }
        return min_index;
    }
};
