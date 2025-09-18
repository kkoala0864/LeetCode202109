#include <data_type.h>

class FoodRatings {
public:
	FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
		int size = foods.size();
		for (int i = 0 ; i < size ; ++i) {
			foodInfo[foods[i]] = pair<string, int>(cuisines[i], ratings[i]);
			foodRating[cuisines[i]][ratings[i]].emplace(foods[i]);
		}
	}

	void changeRating(string food, int newRating) {
		int oldR = foodInfo[food].second;
		string cs = foodInfo[food].first;
		foodInfo[food].second = newRating;

		foodRating[cs][oldR].erase(food);
		if (foodRating[cs][oldR].empty()) foodRating[cs].erase(oldR);
		foodRating[cs][newRating].emplace(food);
	}

	string highestRated(string cuisine) {
		return *(foodRating[cuisine].begin()->second.begin());
	}

private:
	unordered_map<string, pair<string, int>> foodInfo;
	unordered_map<string, map<int, set<string>, greater<>>> foodRating;
	virtual ~FoodRatings() {
	}
	FoodRatings &operator=(const FoodRatings &source);
	FoodRatings(const FoodRatings &);
};
