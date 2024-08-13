#include <data_type.h>
#include <vector>

using std::vector;

class ProductOfNumbers {
    public :
	ProductOfNumbers() {
		preProduct = {1};
	}

	void add(int num) {
		if (num == 0) preProduct = {1};
		else preProduct.emplace_back(preProduct.back() * (long long)num);
	}

	int getProduct(int k) {
		if (k >= preProduct.size()) return 0;
		return preProduct.back() / preProduct[preProduct.size() - k - 1];
	}
    private :
	vector<long long> preProduct;
        virtual ~ProductOfNumbers() {}
        ProductOfNumbers& operator=(const ProductOfNumbers& source);
        ProductOfNumbers(const ProductOfNumbers&);
};

