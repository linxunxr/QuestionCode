/**
 * Copyright (C), 2024-07-15
 * @author LinXun
 * @date 24-7-15 下午8:55
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num;
    vector<int> gems;
    int money;
    cin >> num;
    while (num--) {
        int temp;
        cin >> temp;
        gems.push_back(temp);
    }
    cin >> money;
    int leftIndex = 0, rightIndex = 0, sumMoney = 0, maxGems = 0;
    while (rightIndex < num) {
        sumMoney += gems[rightIndex];
        while (sumMoney > money) {
            sumMoney -= gems[leftIndex++];
        }
        maxGems = max(maxGems, rightIndex - leftIndex + 1);
        rightIndex++;
    }
    cout << maxGems << endl;
    return 0;
}