class Twitter {
private:
    int timestamp;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (const auto& tweet : tweets[userId]) {
            minHeap.push(tweet);
            if (minHeap.size() > 10) minHeap.pop();
        }

        for (int followeeId : following[userId]) {
            for (const auto& tweet : tweets[followeeId]) {
                minHeap.push(tweet);
                if (minHeap.size() > 10) minHeap.pop();
            }
        }

        vector<int> feed;
        while (!minHeap.empty()) {
            feed.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(feed.begin(), feed.end());
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (following[followerId].count(followeeId)) {
            following[followerId].erase(followeeId);
        }
    }
};