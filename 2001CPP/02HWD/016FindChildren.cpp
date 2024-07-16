/**
 * Copyright (C), 2024-07-16
 * @author LinXun
 * @date 24-7-16 下午1:38
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <iostream>
#include <map>
using namespace std;

int main() {
    // key 报告有多少个孩子 value 多少个孩子
    map<int, int> childMap;
    int input;
    int result = 0;
    while (cin >> input) {
        if (childMap.find(input) == childMap.end()) {
            childMap.insert({input, 1});
        } else {
            childMap.find(input)->second++;
        }
        if (cin.get() == '\n') {
            break;
        }
    }
    for (auto item : childMap) {
        int friends = item.first;
        int count = item.second;
        int villages = count % (friends + 1) ? count / (friends + 1) + 1 : count / (friends + 1);
        result += villages * (friends + 1);
    }
    cout << result << endl;
}