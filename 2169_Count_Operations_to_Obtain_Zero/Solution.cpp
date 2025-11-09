#include <Solution.h>

int Solution::countOperations(int num1, int num2) {
    if (num1 < num2) swap(num1, num2);
    if (num2 == 0) return 0;
    return (num1 / num2) + countOperations(num2, num1 % num2);
}
