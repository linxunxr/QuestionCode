/**
 * Copyright (C), 2024-07-16
 * @author LinXun
 * @date 24-7-16 上午10:41
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int input;
    map<int, int> countMap;
    while (cin >> input) {
        if (countMap.count(input)) {
            countMap[input]++;
        } else {
            countMap[input] = 1;
        }
    }
    int maxCount = 0;
    for (auto cout : countMap) {
        maxCount = max(maxCount, cout.second);
    }
    vector<int> modeNumbers;
    for (auto cout : countMap) {
        if (cout.second == maxCount) {
            modeNumbers.push_back(cout.first);
        }
    }
    sort(modeNumbers.begin(), modeNumbers.end());
    if (modeNumbers.size() % 2 != 0) {
        int index = (modeNumbers.size() + 1) / 2 - 1;
        cout <<  modeNumbers[index] << endl;
    } else {
        int left = modeNumbers.size() / 2 - 1;
        int right = modeNumbers.size() / 2;
        cout << (modeNumbers[left] + modeNumbers[right]) / 2 << endl;
    }
    return 0;
}