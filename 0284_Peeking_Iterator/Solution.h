#include <vector>
using std::vector;

class Iterator {
	private:
		struct Data;
		Data* data;
	public:
		Iterator(const vector<int>& nums);
		Iterator(const Iterator& iter);

		// Returns the next element in the iteration.
		int next();

		// Returns true if the iteration has more elements.
		bool hasNext() const;
};

class PeekingIterator {
    public :
	    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		    // Initialize any member here.
		    // **DO NOT** save a copy of nums and manipulate it directly.
		    // You should only use the Iterator interface methods.
		    cur = this->Iterator::next();
	    }

	    // Returns the next element in the iteration without advancing the iterator.
	    int peek() {
		return cur;
	    }

	    // hasNext() and next() should behave the same as in the Iterator interface.
	    // Override them if needed.
	    int next() {
		    int top = cur;
		    if (this->Iterator::hasNext()) cur = this->Iterator::next();
		    else cur = -1;
		    return top;
	    }

	    bool hasNext() const {
		    return cur > 0;
	    }
    private :
	    int cur = -1;
        virtual ~PeekingIterator() {}
        PeekingIterator& operator=(const PeekingIterator& source);
        PeekingIterator(const PeekingIterator&);
};

