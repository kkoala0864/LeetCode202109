#include <stack>
#include <unordered_map>

using std::stack;
using std::unordered_map;

class FreqStack {
public:
	FreqStack() {
		maxfreq = 0;
	}

	void push(int val) {
		++freq[val];
		if (freq[val] > maxfreq)
			maxfreq = freq[val];
		group[freq[val]].emplace(val);
	}

	int pop() {
		int x = group[maxfreq].top();
		group[maxfreq].pop();
		--freq[x];
		if (group[maxfreq].size() == 0)
			--maxfreq;
		return x;
	}

private:
	unordered_map<int, int> freq;
	unordered_map<int, stack<int>> group;
	int maxfreq;
	virtual ~FreqStack() {
	}
	FreqStack &operator=(const FreqStack &source);
	FreqStack(const FreqStack &);
};
