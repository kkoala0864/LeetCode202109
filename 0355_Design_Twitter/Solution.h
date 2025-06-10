#include <data_type.h>
#include <tuple>

class Twitter {
public:
	Twitter() {
	}

	void postTweet(int userId, int tweetId) {
		tweetForUser[userId].emplace_back(pair<int, int>(timeStamp++, tweetId));
	}

	vector<int> getNewsFeed(int userId) {
		priority_queue<tuple<int, int, int>> pq;
		fw[userId].emplace(userId);

		for (const auto& id : fw[userId]) {
			if (tweetForUser[id].empty()) continue;
			pq.emplace(make_tuple(tweetForUser[id].back().first, id, tweetForUser[id].size() - 1));
		}

		vector<int> ret;
		while (ret.size() < 10 && !pq.empty()) {
			auto [time, id, idx] = pq.top();
			pq.pop();
			ret.emplace_back(tweetForUser[id][idx].second);
			if (idx > 0) {
				pq.emplace(make_tuple(tweetForUser[id][idx-1].first, id, idx - 1));
			}
		}
		return ret;
	}

	void follow(int followerId, int followeeId) {
		fw[followerId].emplace(followeeId);
	}

	void unfollow(int followerId, int followeeId) {
		fw[followerId].erase(followeeId);
	}

private:
	unordered_map<int, unordered_set<int>> fw;
	unordered_map<int, vector<pair<int, int>>> tweetForUser;
	int timeStamp = 1;
	virtual ~Twitter() {
	}
	Twitter &operator=(const Twitter &source);
	Twitter(const Twitter &);
};
