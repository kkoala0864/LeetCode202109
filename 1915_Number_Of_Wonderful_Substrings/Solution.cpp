#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

// xor's reverse operation is xor

long long Solution::wonderfulSubstrings(string word) {
	unordered_map<int, int> m;
	m[0] = 1;

	long long result = 0;
	int mask = 0;

	for (const auto& c : word) {
		mask = mask ^ (1 << (c - 'a'));

		// all even case
		// 0 : means all even case
		// how to get 0 ?
		// mask ^ mask = 0
		result += m[mask];

		++m[mask];

		for (int j = 0 ; j < 10 ; ++j) {
			// each one odd number case
			// only one bit is 1 => 0000000001, 0000000010, 0000000100 .....
			// how to get one bit case from cur mask
			// mask -(xor) x = only one bit case
			// mask -(xor) only one bit case = x
			// mask ^ (1 << j) = x
			result += m[mask ^ (1 << j)];
		}
	}
	return result;
}
