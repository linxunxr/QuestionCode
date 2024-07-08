#include <iostream>
/**
 * Copyright (C), 2024-07-08
 * @author LinXun
 * @date 24-7-8 上午7:49
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    int line;
    cin >>line;
    int result = 0;
    while (line) {
        result += line % 2;
        line /= 2;
    }
    cout << result;
}