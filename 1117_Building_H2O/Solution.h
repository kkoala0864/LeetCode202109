#include <data_type.h>
#include <mutex>
#include <condition_variable>

using namespace std;

class H2O {
public:

	H2O() {
	}

	void hydrogen(function<void()> releaseHydrogen) {
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [&] { return hcnt < 2; });
		++hcnt;
		releaseHydrogen();
		cv.notify_all();
	}

	void oxygen(function<void()> releaseOxygen) {
		unique_lock<mutex> lock(mtx);
		cv.wait(lock, [&] { return hcnt == 2; });
		releaseOxygen();
		hcnt = 0;
		cv.notify_all();
	}

private:
	int hcnt = 0;
	mutex mtx;
	condition_variable cv;
	virtual ~H2O() {
	}
	H2O &operator=(const H2O &source);
	H2O(const H2O &);
};
