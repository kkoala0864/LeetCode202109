#include <data_type.h>

class TwoSum {
	public:
		TwoSum() {

		}

		void add(int number) {
			m.emplace(number);
		}

		bool find(int value) {
			if (m.size() < 2) return false;
			auto l = m.begin();
			auto r = m.end();
			--r;
			while (l != r) {
				int lv = *l;
				int rv = *r;
				int v = lv + rv;
				if (v == value) return true;
				if (v > value) {
					--r;
				} else {
					++l;
				}
			}
			return false;
		}

	private:
		multiset<int> m;
		virtual ~TwoSum() {
		}
		TwoSum &operator=(const TwoSum &source);
		TwoSum(const TwoSum &);
};
