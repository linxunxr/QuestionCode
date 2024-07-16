#include <iostream>
#include <sstream>
#include <string>
#include <vector>
/**
 * Copyright (C), 2024-07-08
 * @author LinXun
 * @date 24-7-8 上午9:27
 * @version 1.0
 * @description: 特定大小的停车场，数组cars[]表示，其中1表示有车，0表示没车。车辆大小不一，小车占1个车位，货车占2个车位，卡车占3个车位。
 */
using namespace std;
void caculate(int &result, int &cnt) {
    result += cnt / 3;
    cnt %= 3;
    result += cnt / 2;
    cnt %= 2;
    result += cnt;
    cnt = 0;
}
int main() {
    vector<int> cars;
    string input;
    getline(cin, input);
    istringstream iss(input);
    string temp;
    while (getline(iss, temp, ',')) {
        cars.push_back(stoi(temp));
    }
    int result = 0, cnt = 0;
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i] == 1) {
            cnt++;
        } else {
            caculate(result, cnt);
        }
    }
    if (cnt) {
        caculate(result, cnt);
    }
    cout << result << endl;
    return 0;
}