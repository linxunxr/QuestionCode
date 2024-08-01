/**
 * Copyright (C), 2024-07-17
 * @author LinXun
 * @date 24-7-17 下午2:09
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/**
 * 查找目标pai数量
 * @param apis API集群数组
 * @param targetNum 目标层级
 * @param targetStr 目标api
 * @return 目标api数量
 */
int getTargetApi(vector<vector<string>> apis, int targetNum, string targetStr) {
    int result = 0;
    for (int i = 0; i < apis.size(); ++i) {
        if (targetNum > apis[i].size()) {
            continue;
        } else {
            if (targetStr == apis[i][targetNum]) {
                result++;
            }
        }
    }
    return result;
}
int main() {
    int num;
    cin >> num;
    cin.ignore();
    vector<vector<string>> apis;
    while (num--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<string> temp;
        string tempStr;
        while (getline(ss, tempStr, '/')) {
            temp.push_back(tempStr);
        }
        apis.push_back(temp);
    }
    // 层级
    int targetNum;
    string targetStr;
    cin >> targetNum >> targetStr;
    cout << getTargetApi(apis, targetNum, targetStr) << endl;
    return 0;
}