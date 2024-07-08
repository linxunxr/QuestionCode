#include <iostream>
#include <string>
/**
 * Copyright (C), 2024-07-07
 * @author LinXun
 * @date 24-7-7 下午7:45
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    string line;
    cin >> line;
    // 双指针
    int leftIndex = 0;
    int rightIndex = line.size() - 1;
    while (leftIndex < rightIndex) {
        swap(line[leftIndex++], line[rightIndex--]);
    }
    cout << line << endl;
}