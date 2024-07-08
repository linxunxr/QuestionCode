#include <iostream>
#include <map>
/**
 * Copyright (C), 2024-07-07
 * @author LinXun
 * @date 24-7-7 上午10:21
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    map<int, int> result;
    int num;
    cin >> num;
    while (num--) {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        result[temp.first] += temp.second;
    }
    for (auto i : result) {
        cout << i.first << ' ' << i.second << endl;
    }
}