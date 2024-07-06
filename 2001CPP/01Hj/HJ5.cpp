#include <iostream>
#include <string>
/**
 * Copyright (C), 2024-07-06
 * @author LinXun
 * @date 24-7-6 下午4:46
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    string line;
    getline(cin, line);
    long result = 0;
    long temp16 = 1;
    for (int i = line.size() - 1; i > 1; i--) {
        int temp = (line[i] >= '0' && line[i] <= '9') ? line[i] - '0' : line[i] - 'A' + 10;
        result += temp * temp16;
        temp16 *= 16;
    }
    cout << result << endl;
}