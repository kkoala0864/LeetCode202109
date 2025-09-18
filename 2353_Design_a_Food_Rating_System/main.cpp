#include <Solution.h>

int main(void) {
	//["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
	//[[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
	vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
	vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
	vector<int> ratings = {9, 12, 8, 15, 14, 7};
	FoodRatings *test = new FoodRatings(foods, cuisines, ratings);
	cout << test->highestRated("korean") << endl;
	cout << test->highestRated("japanese") << endl;
	test->changeRating("sushi", 16);
	cout << test->highestRated("japanese") << endl;
	test->changeRating("ramen", 16);
	cout << test->highestRated("japanese") << endl;
	return 0;
}
