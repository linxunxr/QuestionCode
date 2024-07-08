#include <iostream>
#include <stack>
#include <string>
/**
 * Copyright (C), 2024-07-08
 * @author LinXun
 * @date 24-7-8 上午7:22
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    string line;
    stack<string> result;
    while (cin >> line) {
        result.push(line);
    }
    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
}