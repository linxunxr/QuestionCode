#include <iostream>
/**
 * Copyright (C), 2024-07-06
 * @author LinXun
 * @date 24-7-6 下午3:29
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    int num;
    cin >> num;
    int temp[501] = {0};
    while (num--) {
        int i;
        cin >> i;
        temp[i]++;
    }
    for (int i = 0; i < 501; i++) {
        if (temp[i] == 0) {
            continue;
        } else {
            cout << i << endl;
        }
    }
}