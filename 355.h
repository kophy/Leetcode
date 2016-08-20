class Tweet {
    public:
        Tweet(int id, int time) : id(id), time(time) {}
    private:
        int id;
        int time;
    friend class Twitter;
    friend class Compare;
};

typedef pair<vector<Tweet>::iterator, vector<Tweet>::iterator> TweetPair;

class Compare {
    public:
        bool operator()(TweetPair p1, TweetPair p2 ) {
            return (p1.first->time < p2.first->time);
        }
};

class Twitter {
public:
    Twitter(int t = 0) : time(t) {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert(tweets[userId].begin(), Tweet(tweetId, time++));
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<TweetPair, vector<TweetPair>, Compare> pq;
        vector<int> result;
        for (auto follower : followmap[userId]) {
            if (tweets.count(follower) && tweets[follower].size())
                pq.push(make_pair(tweets[follower].begin(), tweets[follower].end()));
        }
        if (tweets.count(userId) && tweets[userId].size())
            pq.push(make_pair(tweets[userId].begin(),tweets[userId].end()));
        for (int i = 0; i < 10 && !pq.empty(); ++i) {
            auto temp = pq.top();
            pq.pop();
            result.push_back(temp.first->id);
            ++temp.first;
            if (temp.first != temp.second)
                pq.push(temp);
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followmap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followmap.count(followerId))
            followmap[followerId].erase(followeeId);
    }

private:
    int time;
    unordered_map<int, unordered_set<int>> followmap;
    unordered_map<int, vector<Tweet>> tweets;
};