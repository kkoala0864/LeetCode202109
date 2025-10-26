#include <data_type.h>

class Bank {
public:
	Bank(vector<long long>& balance) {
		acnt = balance;
	}

	bool transfer(int account1, int account2, long long money) {
		if (account1 < 1 || account1 > acnt.size()) return false;
		if (account2 < 1 || account2 > acnt.size()) return false;
		if (acnt[account1 - 1] < money) return false;
		acnt[account2 - 1] += money;
		acnt[account1 - 1] -= money;
		return true;
	}

	bool deposit(int account, long long money) {
		if (account < 1 || account > acnt.size()) return false;
		acnt[account - 1] += money;
		return true;
	}

	bool withdraw(int account, long long money) {
		if (account < 1 || account > acnt.size()) return false;
		if (acnt[account - 1] < money) return false;
		acnt[account - 1] -= money;
		return true;
	}

private:
	vector<long long> acnt;
	virtual ~Bank() {
	}
	Bank &operator=(const Bank &source);
	Bank(const Bank &);
};
