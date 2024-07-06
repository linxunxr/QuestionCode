#include <iostream>
#include <sstream>
#include <string>
/**
 * Copyright (C), 2024-07-05
 * @author LinXun
 * @date 24-7-5 上午11:06
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    string line;
    int result;
    while (getline(cin, line)) {
        stringstream ss(line);
        string temp;
        while (ss >> temp) {
            result = temp.size();
        }
        cout << result << endl;
    }
}