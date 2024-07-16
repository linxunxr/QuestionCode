/**
 * Copyright (C), 2024-07-15
 * @author LinXun
 * @date 24-7-15 下午9:18
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <cmath>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int g_result = INT_MAX;
int g_sum = 0;
int g_targetSum = 0;

/**
 *
 * @param groupStrength 队伍实力
 * @param currentIndex 队伍正在选择的玩家id
 * @param count 队伍已选择玩家数量
 * @param currentSum 当前实力之和
 */
void dfs(vector<int> &groupStrength, int currentIndex, int count, int currentSum) {
    // 当一个队伍选择了5名玩家
    if (count == 5) {
        int otherGroupSum = g_sum - currentIndex;
        g_result = min(g_result, abs(currentSum - otherGroupSum));
        return;
    }
    if (currentIndex == 10) {
        return;
    }
    dfs(groupStrength, currentIndex + 1, count + 1, currentSum + groupStrength[currentIndex]);
    dfs(groupStrength, currentIndex + 1, count, currentSum);
}

int main() {
    vector<int> groupStrength;
    for (int i = 0; i < 10; ++i) {
        int temp;
        cin >> temp;
        groupStrength.push_back(temp);
        g_sum += temp;
    }
    g_targetSum = g_sum / 2;
    dfs(groupStrength, 0, 0, 0);
    cout << g_result << endl;
    return 0;
}