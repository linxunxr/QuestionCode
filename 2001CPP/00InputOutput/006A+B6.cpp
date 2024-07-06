/**
 * Copyright (C), 2024-07-04
 * @author LinXun
 * @date 24-7-4 上午9:43
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
#include <iostream>
using namespace std;

int main() {
    int num;
    while (cin >> num) {
        int sum = 0;
        while (num--) {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }
        cout << sum << endl;
    }
    return 0;
}