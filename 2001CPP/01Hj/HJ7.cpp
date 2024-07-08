#include <complex>
#include <iostream>
/**
 * Copyright (C), 2024-07-07
 * @author LinXun
 * @date 24-7-7 上午9:51
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    float input;
    cin >> input;
    // 整数部分
    int result = input;
    // 小数部分
    float decimalPort = fabs(input - result);
    // 判断
    if (decimalPort >= 0.5) {
        result += 1;
    }
    cout << result << endl;
}