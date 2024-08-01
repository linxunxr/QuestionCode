/**
 * Copyright (C), 2024-07-17
 * @author LinXun
 * @date 24-7-17 下午2:42
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

/**
 * 判断谁更优胜
 * @param shape1 形状1
 * @param shape2 形状2
 * @return 优胜形状
 */
char whoWin(char shape1, char shape2) {
    if (abs(shape1 - shape2) == 1) {
        return shape1 > shape2 ? shape2 : shape1;
    } else {
        return shape1 > shape2 ? shape1 : shape2;
    }
}

/**
 * 判断是否存在赢家 如果存在则找出赢家 如果不存在则返回false
 * @param data 游戏数据map
 * @param result 游戏结果
 * @return 是否存在赢家
 */
bool isWin(map<char, vector<string>> &data, vector<string> &result) {
    if (data.size() != 2) {
        return false;
    }
    char winShape;
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it != data.begin()) {
            winShape = whoWin(data.begin()->first, it->first);
        }
    }
    result = data.find(winShape)->second;
    sort(result.begin(), result.end());
    return true;
}

int main() {
    // 出拳形状 出拳玩家名
    map<char, vector<string>> gameData;
    string playerName;
    char shape;
    while (cin >> playerName >> shape) {
        if (gameData.find(shape) != gameData.end()) {
            gameData.find(shape)->second.push_back(playerName);
        } else {
            vector<string> temp;
            temp.push_back(playerName);
            gameData.insert({shape, temp});
        }
    }
    vector<string> result;
    if (!isWin(gameData, result)) {
        cout << "NULL" << endl;
    } else {
        for (string temp : result) {
            cout << temp << endl;
        }
    }
    return 0;
}