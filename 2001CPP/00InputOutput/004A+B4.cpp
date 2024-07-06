/**
 * Copyright (C), 2024-07-04
 * @author LinXun
 * @date 24-7-4 上午9:14
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
#include <iostream>
using namespace std;

int main() {
    int num;
    while (cin >> num) {
        if (num == 0) {
            break;
        } else {
            int sum = 0;
            while (num > 0) {
                int tmp;
                cin >> tmp;
                sum += tmp;
                num--;
            }
            cout << sum << endl;
        }
    }
}