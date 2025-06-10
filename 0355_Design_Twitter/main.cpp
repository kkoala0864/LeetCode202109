#include <Solution.h>

int main(void) {
	//["Twitter","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","getNewsFeed"]
	//[[],[1,5],[1,3],[1,101],[1,13],[1,10],[1,2],[1,94],[1,505],[1,333],[1]]

	Twitter *test = new Twitter();
	test->postTweet(1, 5);
	test->postTweet(1, 3);
	test->postTweet(1, 101);
	test->postTweet(1, 13);
	test->postTweet(1, 10);
	test->postTweet(1, 2);
	test->postTweet(1, 94);
	test->postTweet(1, 505);
	test->postTweet(1, 333);
	std::vector<int> result = test->getNewsFeed(1);
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
