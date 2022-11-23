#include<unordered_set>
#include<queue>
#include<unordered_map>
struct tweet{
    int tweetId;
    int timestamp;
    int userId;//for convenience
};
class cmp_class{
public:
    bool operator()(const struct tweet& t1, const struct tweet& t2){
        return t1.timestamp < t2.timestamp;//max heap
    }
};
class Twitter {
public:
    const int max_user = 502;
    vector<unordered_set<int>> user_following;
    vector<vector<struct tweet>> user_tweet;
    int timestamp;
    Twitter() {
        user_following = vector<unordered_set<int>>(max_user, unordered_set<int>());
        for(int i=0;i<max_user;i++)
            user_following[i].insert(i);
        
        user_tweet = vector<vector<struct tweet>>(max_user, vector<struct tweet>());
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        struct tweet tweet1 = {tweetId, timestamp++, userId};
        user_tweet[userId].push_back( tweet1 );
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<struct tweet, vector<struct tweet>, cmp_class> max_heap;
        //NOTE: Replenishing by the used followee, which takes 1 polling at first,  is better than polling each time when selecting a new recent tweet feed.
        unordered_map<int,int> followee2unusedTweetIdx;
        for(int followee: user_following[userId]){
            if(user_tweet[followee].size() != 0){
                max_heap.push( user_tweet[followee].back() );
                followee2unusedTweetIdx[followee] = user_tweet[followee].size()-1;
            }
        }
        
        //now select at most 10 recent tweets
        vector<int> recent10_tweetId;
        for(int i=0;i<10;i++){
            if(max_heap.size() == 0)break;
            
            struct tweet t = max_heap.top();
            max_heap.pop();
            recent10_tweetId.push_back(t.tweetId);
            
            //NOTE: replenish
            //NOTE: if this followee's most recent can't be selected, then his/her other tweets shall not be in queue
            if(--followee2unusedTweetIdx[t.userId] >= 0){
                max_heap.push( user_tweet[t.userId][ followee2unusedTweetIdx[t.userId] ] );
            }
        }
        return recent10_tweetId;
    }
    
    void follow(int followerId, int followeeId) {
        user_following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        user_following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
