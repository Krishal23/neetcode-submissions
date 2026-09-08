class Twitter {
public:
    struct USER{
        vector<pair<int,int>>tweets;
        unordered_set<int>followings;
    };
    
    vector<USER>users;
    int time;
    Twitter() {
        users.resize(5001);
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        users[userId].tweets.push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        auto feed=[&](int uid){
            for(auto [t,tid]:users[uid].tweets){
                if(pq.size()>=10){
                    if(pq.top().first<t){
                        pq.pop();
                        pq.push({t,tid});
                    }
                }else{
                    pq.push({t,tid});
                }
            }
        };
        feed(userId);
        for(int foll:users[userId].followings){
            feed(foll);
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].followings.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].followings.erase(followeeId);
    }
};
