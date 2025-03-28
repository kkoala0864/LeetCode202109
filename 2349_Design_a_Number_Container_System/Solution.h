#include <data_type.h>
#include <unordered_map>
#include <set>

using std::set;
using std::unordered_map;

class NumberContainers {
public:
	NumberContainers() {
	}

	void change(int index, int number) {
		if (numberMap.count(index)) {
			indexMap[numberMap[index]].erase(index);
		}
		numberMap[index] = number;
		indexMap[number].emplace(index);
	}

	int find(int number) {
		if (indexMap.count(number) == 0 || indexMap[number].empty())
			return -1;
		return *(indexMap[number].begin());
	}

private:
	unordered_map<int, int> numberMap;
	unordered_map<int, set<int>> indexMap;
	virtual ~NumberContainers() {
	}
	NumberContainers &operator=(const NumberContainers &source);
	NumberContainers(const NumberContainers &);
};
