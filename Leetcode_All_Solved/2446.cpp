class Solution {
public:
    inline int to_min(const string& s){
        return stoi( s.substr(0, 2) ) * 60 + stoi( s.substr(3) );
    }

    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int start1 = to_min(event1[0]);
        int start2 = to_min(event2[0]);

        if(start1 <= start2) return start2 <= to_min(event1[1]);
        else return start1 <= to_min(event2[1]);
    }
};
