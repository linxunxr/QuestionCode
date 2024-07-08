#include <iostream>
#include <set>
#include <string>
/**
 * Copyright (C), 2024-07-07
 * @author LinXun
 * @date 24-7-7 下午5:22
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    string line;
    cin >> line;
    set<char> temp;
    for (int i = 0; i < line.size(); i++) {
        temp.insert(line[i]);
    }
    cout << temp.size() << endl;
}