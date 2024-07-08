#include <iostream>
/**
 * Copyright (C), 2024-07-07
 * @author LinXun
 * @date 24-7-7 上午10:39
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    int input;
    cin >> input;
    int result[10] = {0};
    while (input > 0) {
        int temp = input % 10;
        input /= 10;
        if (result[temp] == 0) {
            cout << temp;
            result[temp] = 1;
        }
    }
}