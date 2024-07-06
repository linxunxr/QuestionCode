#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
/**
 * Copyright (C), 2024-07-04
 * @author LinXun
 * @date 24-7-4 上午11:19
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        vector<string> str;
        stringstream ss(line);
        string tmp;
        while (ss >> tmp) {
            str.push_back(tmp);
        }
        sort(str.begin(), str.end());
        for (string st : str) {
            cout << st << ' ';
        }
        cout << endl;
    }
}