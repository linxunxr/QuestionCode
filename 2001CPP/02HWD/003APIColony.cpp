#include <iostream>
#include <sstream>
#include <vector>
/**
 * Copyright (C), 2024-07-08
 * @author LinXun
 * @date 24-7-8 下午5:09
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    int num;
    vector<vector<string>> apis;
    cin >> num;
    int targetCnt;
    string targetString;
    cin.ignore();
    while (num--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        string temp;
        vector<string> tmp;
        while (getline(ss, temp, '/')) {
            tmp.push_back(temp);
        }
        apis.push_back(tmp);
    }
    cin >> targetCnt >> targetString;
    int result = 0;
    for (int i = 0; i < apis.size(); i++) {
        if (apis[i].size() < targetCnt) {
            continue;
        } else {
            if (apis[i][targetCnt] == targetString) {
                result++;
            } else {
                continue;
            }
        }
    }
    cout << result << endl;
}