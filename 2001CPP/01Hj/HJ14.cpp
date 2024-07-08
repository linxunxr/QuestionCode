#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
/**
 * Copyright (C), 2024-07-08
 * @author LinXun
 * @date 24-7-8 上午7:40
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    vector<string> result;
    int num;
    cin >> num;
    while (num--) {
        string temp;
        cin >> temp;
        result.push_back(temp);
    }
    sort(result.begin(), result.end());
    for (auto i : result) {
        cout << i << endl;
    }
}