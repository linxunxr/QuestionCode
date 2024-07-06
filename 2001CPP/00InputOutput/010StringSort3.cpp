#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
/**
 * Copyright (C), 2024-07-05
 * @author LinXun
 * @date 24-7-5 上午9:36
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string tmp;
        vector<string> str;
        while (getline(ss, tmp, ',')) {
            str.push_back(tmp);
        }
        sort(str.begin(), str.end());
        for (int i = 0; i < str.size() - 1; i++) {
            cout << str[i] << ',';
        }
        cout << str[str.size() - 1] << endl;
    }
    return 0;
}