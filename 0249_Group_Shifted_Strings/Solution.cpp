#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_map;
using std::unordered_set;

vector<vector<string>> Solution::groupStrings(vector<string> &strings) {
	unordered_map<int, unordered_set<int>> uMap;
	vector<vector<string>> result;

	for (const auto &word : strings) {
		int size = word.size();
		if (uMap.find(size) == uMap.end()) {
			result.emplace_back(vector<string>(1, word));
			uMap[size] = unordered_set<int>();
			uMap[size].emplace(result.size() - 1);
		} else {
			bool find = false;
			for (const auto &idx : uMap[size]) {
				if (1 == size) {
					find = true;
					result[idx].emplace_back(word);
				} else {
					int i = 0;
					for (; i < word.size() - 1; ++i) {
						int newdiff = word[i + 1] - word[i];
						if (newdiff < 0)
							newdiff += 26;
						int oriDiff = (result[idx][0][i + 1] - result[idx][0][i]);
						if (oriDiff < 0)
							oriDiff += 26;
						if (oriDiff != newdiff)
							break;
					}
					if (i == word.size() - 1) {
						find = true;
						result[idx].emplace_back(word);
						break;
					}
				}
			}
			if (!find) {
				result.emplace_back(vector<string>(1, word));
				uMap[size].emplace(result.size() - 1);
			}
		}
	}
	return result;
}
