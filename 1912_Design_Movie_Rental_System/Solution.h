#include <data_type.h>

class MovieRentingSystem {
public:
	MovieRentingSystem(int n, vector<vector<int>>& entries) {
		info = vector<unordered_map<int, int>>(n, unordered_map<int, int>());
		for (const auto& e : entries) {
			info[e[0]][e[1]] = e[2];
			unrents[e[1]].emplace(pair<int, int>(e[2], e[0]));
		}
	}

	vector<int> search(int movie) {
		vector<int> result;
		auto iter = unrents[movie].begin();
		while (result.size() < 5 && iter != unrents[movie].end()) {
			result.emplace_back(iter->second);
			++iter;
		}
		return result;
	}

	void rent(int shop, int movie) {
		int p = info[shop][movie];
		unrents[movie].erase(pair<int, int>(p, shop));
		rs.emplace(vector<int>({p, shop, movie}));
	}

	void drop(int shop, int movie) {
		int p = info[shop][movie];
		rs.erase(vector<int>({p, shop, movie}));
		unrents[movie].emplace(pair<int, int>(p, shop));
	}

	vector<vector<int>> report() {
		auto iter = rs.begin();
		vector<vector<int>> result;
		while (result.size() < 5 && iter != rs.end()) {
			result.emplace_back(vector<int>({(*iter)[1], (*iter)[2]}));
			++iter;
		}
		return result;
	}

private:
	set<vector<int>> rs;
	// movie, [price, shop]
	unordered_map<int, set<pair<int, int>>> unrents;
	vector<unordered_map<int, int>> info;

	virtual ~MovieRentingSystem() {
	}
	MovieRentingSystem &operator=(const MovieRentingSystem &source);
	MovieRentingSystem(const MovieRentingSystem &);
};
