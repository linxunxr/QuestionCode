#include <iostream>
#include <set>
#include <sstream>
#include <vector>
/**
 * Copyright (C), 2024-07-14
 * @author LinXun
 * @date 24-7-14 上午11:18
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

/**
 * 深搜
 * @param contacts 接触矩阵
 * @param visited 标记数组
 * @param start 开始节点
 */
void dfs(vector<vector<bool>> &contacts, vector<bool> &visited, int start) {
    // 标记当前节点为已访问
    visited[start] = true;
    for (size_t i = 0; i < contacts.size(); ++i) {
        // 如果当前节点与其他节点有接触，并且该节点未被访问
        if (contacts[start][i] && !visited[i]) {
            dfs(contacts, visited, i);
        }
    }
}

int main() {
    int num;
    cin >> num;
    cin.ignore();
    string input;
    getline(cin, input);
    istringstream iss(input);
    string caseIndex;
    set<int> confirmedCase;
    // 读取确诊病例编号
    while (getline(iss, caseIndex, ',')) {
        confirmedCase.insert(stoi(caseIndex));
    }
    vector<vector<bool>> contacts(num, vector<bool>(num));
    vector<bool> visited(num, false);
    // 构建接触矩阵
    for (int i = 0; i < num; ++i) {
        getline(cin, input);
        istringstream rs(input);
        string contact;
        int j = 0;
        while (getline(rs, contact, ',')) {
            contacts[i][j++] = contact == "1";
        }
    }
    // 对每个病例执行深搜
    for (int index : confirmedCase) {
        if (!visited[index]) {
            dfs(contacts, visited, index);
        }
    }
    int result = 0;
    for (int i = 0; i < num; ++i) {
        if (visited[i] && confirmedCase.find(i) == confirmedCase.end()) {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}