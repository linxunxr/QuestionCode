/**
 * Copyright (C), 2024-07-16
 * @author LinXun
 * @date 24-7-16 下午2:53
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <iostream>
using namespace std;

int main() {
    long countryXID, countryYID, countryXNum, countryYNum;
    cin >> countryXID >> countryYID >> countryXNum >> countryYNum;
    long minEmployeeID = countryXNum + countryYNum;
    long maxEmployeeID = 1e18L;
    while (minEmployeeID <= maxEmployeeID) {
        long midEmployeeID = minEmployeeID + (maxEmployeeID - minEmployeeID) / 2;
        // 不能去X
        long notXNum = midEmployeeID / countryXID;
        long notYNum = midEmployeeID / countryYID;
        long notBoth = midEmployeeID / (countryXID * countryYID);
        long canNum = midEmployeeID - notXNum - notYNum + notBoth;
        long needXNum = max(0L, countryXNum - notYNum + notBoth);
        long needYNum = max(0L, countryYNum - notXNum + notBoth);
        if (needXNum + needYNum <= canNum) {
            maxEmployeeID = midEmployeeID - 1;
        } else {
            minEmployeeID = midEmployeeID + 1;
        }
    }
    cout << minEmployeeID << endl;
}