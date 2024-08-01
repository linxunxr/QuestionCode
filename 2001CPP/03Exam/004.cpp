/**
 * Copyright (C), 2024-07-20
 * @author LinXun
 * @date 24-7-20 下午4:02
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void caculate(string &result, string longStr, long long index, bool flag) {
    if (flag) {
        result.push_back(((longStr[index++] - '0') + 1) + '0');
    }
    for (index; index < longStr.size(); ++index) {
        result.push_back(longStr[index]);
    }
}
// 有A B两个很大的数，计算他们的和
int main() {
    string result;
    string inputA;
    string inputB;
    getline(cin, inputA);
    getline(cin, inputB);
    if (inputA.empty() || inputB.empty()) {
        result = inputA.empty() ? inputB : inputA;
        cout << result << endl;
        return 0;
    }
    reverse(inputA.begin(), inputA.end());
    reverse(inputB.begin(), inputB.end());
    bool flag = false;
    for (long long i = 0; i < min(inputA.size(), inputB.size()); ++i) {
        int a = inputA[i] - '0';
        int b = inputB[i] - '0';
        int temp = 0;
        if (flag) {
            temp = a + b + 1;
        } else {
            temp = a + b;
        }
        if (temp >= 10) {
            flag = true;
            result.push_back((temp - 10) + '0');
        } else {
            flag = false;
            result.push_back((temp + '0'));
        }
    }
    if (inputA.size() > inputB.size()) {
        caculate(result, inputA, inputA.size() - inputB.size(), flag);
    } else if (inputA.size() < inputB.size()) {
        caculate(result, inputB, inputB.size() - inputA.size(), flag);
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
    return 0;
}