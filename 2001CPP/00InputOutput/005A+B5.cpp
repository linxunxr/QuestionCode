/**
 * Copyright (C), 2024-07-04
 * @author LinXun
 * @date 24-7-4 上午9:30
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    while (num > 0) {
        int num1;
        cin >> num1;
        int sum = 0;
        while (num1 > 0) {
            int tmp;
            cin >> tmp;
            sum += tmp;
            num1--;
        }
        cout << sum << endl;
        num--;
    }
}
