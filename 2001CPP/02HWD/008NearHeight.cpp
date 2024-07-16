/**
 * Copyright (C), 2024-07-12
 * @author LinXun
 * @date 24-7-12 下午8:38
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <algorithm>
#include <iostream>
#include <valarray>
#include <vector>
using namespace std;

int main() {
    int height, num;
    cin >> height >> num;
    vector<int> heights;
    while (num--) {
        int temp;
        cin >> temp;
        heights.push_back(temp);
    }
    sort(heights.begin(), heights.end(), [height](int a, int b) {
        int diffA = abs(a - height);
        int diffB = abs(b - height);
        if (diffA == diffB) {
            return a < b;
        }
        return diffA < diffB;
    });
    for (int i : heights) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}