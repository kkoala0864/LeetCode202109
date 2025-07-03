#include <Solution.h>

int main(void) {
	//["VideoSharingPlatform", "upload", "upload", "remove", "remove", "upload", "watch", "watch", "like", "dislike", "dislike", "getLikesAndDislikes", "getViews"]
	//[[], ["123"], ["456"], [4], [0], ["789"], [1, 0, 5], [1, 0, 1], [1], [1], [1], [1], [1]]
	VideoSharingPlatform* test = new VideoSharingPlatform();
	cout << test->upload("123") << endl;
	cout << test->upload("456") << endl;
	test->remove(4);
	test->remove(0);
	cout << test->upload("789") << endl;
	cout << test->watch(1, 0, 5) << endl;
	cout << test->watch(1, 0, 1) << endl;
	test->like(1);
	test->dislike(1);
	test->dislike(1);
	auto result = test->getLikesAndDislikes(1);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	cout << test->getViews(1) << endl;
	return 0;
}
