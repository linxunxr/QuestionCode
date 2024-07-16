#include <iostream>
#include <vector>
/**
 * Copyright (C), 2024-07-10
 * @author LinXun
 * @date 24-7-10 下午9:22
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

int main() {
    int num, sumMoney, sumRisk;
    cin >> num >> sumMoney >> sumRisk;
    vector<int> returns, risks, price;
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        returns.push_back(temp);
    }
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        risks.push_back(temp);
    }
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        price.push_back(temp);
    }
    int maxReturn = 0;
    vector<int> bestInvest(num, 0);
    for (int i = 0; i < num; i++) {
        // 如果单个项目的风险在容忍度范围内
        if (risks[i] <= sumRisk) {
            int invest = min(sumMoney, price[i]);
            // 当前回报
            int currentReturn = invest * returns[i];
            if (currentReturn > maxReturn) {
                maxReturn = currentReturn;
                // 更新投资方案
                fill(bestInvest.begin(), bestInvest.end(), 0);
                bestInvest[i] = invest;
            }
        }
        // 寻找两个项目组合
        for (int j = i + 1; j < num; j++) {
            if (risks[i] + risks[j] < sumRisk) {
                int investI, investJ;
                if (returns[i] > returns[j]) {
                    investI = min(sumMoney, price[i]);
                    investJ = min(sumMoney - investI, price[j]);
                } else {
                    investJ = min(sumMoney, price[j]);
                    investI = min(sumMoney - investJ, price[i]);
                }
                int currentReturn = investI * returns[i] + investJ * returns[j];
                if (currentReturn > maxReturn) {
                    maxReturn = currentReturn;
                    // 更新投资方案
                    fill(bestInvest.begin(), bestInvest.end(), 0);
                    bestInvest[i] = investI;
                    bestInvest[j] = investJ;
                }
            }
        }
    }
    for (int invest : bestInvest) {
        cout << invest << " ";
    }
    cout << endl;
    return 0;
}