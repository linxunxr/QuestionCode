/**
 * Copyright (C), 2024-07-15
 * @author LinXun
 * @date 24-7-15 下午10:01
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int num, time;
    cin >> num >> time;
    vector<pair<int, int>> tasks;
    while (num--) {
        int deadline, score;
        cin >> deadline >> score;
        tasks.push_back({deadline, score});
    }
    map<int, int> resultTasks;
    for (int i = 0; i < tasks.size(); ++i) {
        int deadline = tasks[i].first;
        int score = tasks[i].second;
        if (deadline > time) {
            auto minElement = min_element(resultTasks.begin(), resultTasks.end(), [](const auto& a, const auto& b) {
                return a.second < b.second;
            });
            if (score > minElement->second) {
                resultTasks.erase(minElement);
                resultTasks.insert({deadline, score});
            }
            continue;
        }
        if (resultTasks.find(deadline) == resultTasks.end()) {
            resultTasks.insert({deadline, score});
        } else if (resultTasks.find(deadline)->second < score) {
            resultTasks.find(deadline)->second = score;
        }
    }
    int result = 0;
    for (const auto& kv : resultTasks) {
        result += kv.second;
    }
    cout << result << endl;
    return 0;
}