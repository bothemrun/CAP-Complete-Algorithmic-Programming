class Solution {
public:
    vector<string> ans;
    void format_ans(int hour, int minute){
        string ans1 = to_string(hour) + ":";
        if(minute < 10)ans1 += "0";
        ans1 += to_string(minute);
        ans.push_back(ans1);
    }
    void dfs(int turnedOn, int considered, int hour, int minute){
        if(hour > 11 || minute > 59)return;
        if(turnedOn == 0){
            format_ans(hour, minute);
            return;
        }
        if(considered >= 10)return;
        
        //tree: choose or not
        dfs(turnedOn, considered+1, hour, minute);
        if(considered < 4) dfs(turnedOn-1, considered+1, hour + (1 << considered), minute);
        else dfs(turnedOn-1, considered+1, hour, minute + (1 << (considered-4) ) );
    }
    vector<string> readBinaryWatch(int turnedOn) {
        dfs(turnedOn, 0, 0, 0);
        return ans;
    }
};
