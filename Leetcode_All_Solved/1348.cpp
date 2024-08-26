//m0
//naive, each operation in O(Q)

//O(Q * Q)
//seems like TLE, but practically good, 55ms beats 97% C++.
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class TweetCounts {
public:
    unordered_map<string, vector<int>> name2time;

    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        name2time[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int delta = 60;
        if(freq=="hour") delta = 60*60;
        else if(freq=="day") delta = 60*60*60;

        vector<int> ans( (endTime-startTime) / delta + 1 );
        for(const int& time: name2time[tweetName])if(startTime <= time && time <= endTime){
            ans[ (time - startTime) / delta ]++;
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
