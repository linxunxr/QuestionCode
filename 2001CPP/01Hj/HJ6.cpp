#include <iostream>
#include <valarray>
/**
 * Copyright (C), 2024-07-06
 * @author LinXun
 * @date 24-7-6 下午5:56
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    long num;
    cin >> num;
    for (long i = 2; i <= sqrt(num) && i <= num; i++) {
        while (num % i == 0) {
            cout << i << " ";
            num /= i;
        }
    }
    if (num - 1) {
        cout << num << " ";
    }
    return 0;
}