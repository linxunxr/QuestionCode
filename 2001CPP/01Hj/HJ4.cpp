#include <iostream>
#include <string>
/**
 * Copyright (C), 2024-07-06
 * @author LinXun
 * @date 24-7-6 下午3:49
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    string line;
    getline(cin, line);
    if (line.size() == 0) {
        return 0;
    }
    if (line.size() % 8 != 0) {
        int remain = 8 - (line.size() % 8);
        while (remain--) {
            line.push_back('0');
        }
    }
    string temp = "";
    for (int i = 0; i < line.size(); i++) {
        if (i % 8 == 0 && i != 0 && i != line.size() - 1) {
            cout << temp << endl;
            temp = "";
            temp.push_back(line[i]);
        } else {
            temp.push_back(line[i]);
        }
    }
    cout << temp << endl;
}