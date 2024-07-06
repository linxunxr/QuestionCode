#include <iostream>
#include <string>
#include <unordered_map>
/**
 * Copyright (C), 2024-07-05
 * @author LinXun
 * @date 24-7-5 下午12:59
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    string line;
    char target;
    getline(cin, line) >> target;
    unordered_map<char, size_t> map;
    for (char i : line) {
        ++map[tolower(i)];
    }
    cout << map[tolower(target)] << endl;
}