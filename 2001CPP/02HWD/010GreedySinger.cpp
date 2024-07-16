/**
 * Copyright (C), 2024-07-14
 * @author LinXun
 * @date 24-7-14 下午12:28
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // 总天数 城市数量
    int days, cities;
    cin >> days >> cities;
    // 每两城市之间耗费的时间
    vector<int> travelDays(cities + 1);
    for (int i = 0; i <= cities; ++i) {
        cin >> travelDays[i];
    }
    // 每个城市收入预期 每个城市收入递减值
    vector<int> M(cities), D(cities);
    for (int i = 0; i < cities; ++i) {
        cin >> M[i] >> D[i];
    }
    // 计算必需花费的路程时间
    int roadCost = 0;
    for (int i = 0; i <= cities; ++i) {
        roadCost += travelDays[i];
    }
    // 可用于卖唱赚钱的事件
    int remain = days - roadCost;
    // 优先队列 记录每天收益
    priority_queue<int, vector<int>, greater<int>> earningQueue;
    // 遍历每个城市
    for (int i = 0; i < cities; ++i) {
        // 当前城市卖唱天数
        int thisDays = 0;
        while (true) {
            // 今日收益
            int profitToday = max(M[i] - thisDays * D[i], 0);
            if (earningQueue.size() < remain) {
                earningQueue.push(profitToday);
            } else {
                if (!earningQueue.empty() && profitToday > earningQueue.top()) {
                    // 移除最小收益
                    earningQueue.pop();
                    earningQueue.push(profitToday);
                }
            }
            if (profitToday == 0) {
                break;
            }
            thisDays++;
        }
    }
    // 计算总收益
    int maxEarn = 0;
    while (!earningQueue.empty()) {
        maxEarn += earningQueue.top();
        earningQueue.pop();
    }
    cout << maxEarn << endl;
    return 0;
}