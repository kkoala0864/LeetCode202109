#include <data_type.h>
#include <unordered_map>
#include <map>

using std::unordered_map;
using std::map;

class SnapshotArray {
    public :
        SnapshotArray() {}
	SnapshotArray(int length) {
		cur_id = 0;
	}

	void set(int index, int val) {
		m[index][cur_id] = val;
	}

	int snap() {
		return cur_id++;

	}

	int get(int index, int snap_id) {
		auto iter = m[index].lower_bound(snap_id);
		if (iter == m[index].end() || iter->first != snap_id) {
			if (iter == m[index].begin()) {
				return 0;
			} else {
				--iter;
			}
		}
		return iter->second;
	}
    private :
	unordered_map<int, map<int, int>> m;
	int cur_id;
        virtual ~SnapshotArray() {}
        SnapshotArray& operator=(const SnapshotArray& source);
        SnapshotArray(const SnapshotArray&);
};

