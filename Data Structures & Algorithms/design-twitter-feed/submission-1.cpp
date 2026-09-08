class Twitter {
public:
    struct USER{
        vector<pair<int,int>>tweets;
        unordered_set<int>followings;
    };
    struct TweetNode{
        int time;
        int tweetId;
        int userId;
        int indx;
        bool operator<(const TweetNode& other) const {
            return time < other.time;
        }
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
        priority_queue<TweetNode>pq;
        if(!users[userId].tweets.empty()){
            int l=users[userId].tweets.size()-1;
            auto [t,tid]=users[userId].tweets[l];
            pq.push({t,tid,userId,l});
        }
        for(int foll:users[userId].followings){
            if(!users[foll].tweets.empty()){
                int l=users[foll].tweets.size()-1;
                auto [t,tid]=users[foll].tweets[l];
                pq.push({t,tid,foll,l});
            }
        }
        vector<int>ans;
        while(!pq.empty() &&ans.size()<10){
            TweetNode curr=pq.top();
            pq.pop();
            ans.push_back(curr.tweetId);
            if(curr.indx>0){
                int l=curr.indx-1;
                auto [t,tid]=users[curr.userId].tweets[l];
                pq.push({t,tid,curr.userId,l});
            }
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            users[followerId].followings.insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].followings.erase(followeeId);
    }
};
