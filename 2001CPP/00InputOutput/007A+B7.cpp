#include <iostream>
#include <sstream>
#include <string>
/**
 * Copyright (C), 2024-07-04
 * @author LinXun
 * @date 24-7-4 上午10:02
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int num;
        int sum = 0;
        while (ss >> num) {
            sum += num;
        }
        cout << sum << endl;
    }
    return 0;
}
