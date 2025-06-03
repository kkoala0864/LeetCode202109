#include <Solution.h>

int main(void) {
	//["FileSystem","mkdir","ls","ls","mkdir","ls","ls","addContentToFile","ls","ls","ls"]
	//[[],["/goowmfn"],["/goowmfn"],["/"],["/z"],["/"],["/"],["/goowmfn/c","shetopcy"],["/z"],["/goowmfn/c"],["/goowmfn"]]
	FileSystem *test = new FileSystem();
	test->mkdir("/goowmfn");
	auto result = test->ls("/goowmfn");
	for (const auto &s : result) {
		std::cout << s << " ";
	}
	cout << endl;
	result = test->ls("/");
	for (const auto &s : result) {
		std::cout << s << " ";
	}
	cout << endl;
	test->mkdir("/z");
	result = test->ls("/");
	for (const auto &s : result) {
		std::cout << s << " ";
	}
	cout << endl;
	test->addContentToFile("/goowmfn/c", "shetopcy");
	result = test->ls("/z");
	for (const auto &s : result) {
		std::cout << s << " ";
	}
	cout << endl;
	result = test->ls("/goowmfn/c");
	for (const auto &s : result) {
		std::cout << s << " ";
	}
	cout << endl;
	result = test->ls("/goowmfn");
	for (const auto &s : result) {
		std::cout << s << " ";
	}
	cout << endl;

	return 0;
}
