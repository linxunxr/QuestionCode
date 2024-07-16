#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
/**
 * Copyright (C), 2024-07-09
 * @author LinXun
 * @date 24-7-9 下午5:32
 * @version 1.0
 * @description: ${DESCRIPTION}
 */
using namespace std;

struct OpenSource {
    string name, nameSmall;
    int watch, star, fork, issue, mr;
    int sum;
};

/**
 *
 * @param A 开源项目A
 * @param B 开源项目B
 * @return 比较结果
 */
bool compare(OpenSource A, OpenSource B) {
    if (A.sum != B.sum) {
        return A.sum > B.sum;
    } else {
        return A.nameSmall < B.nameSmall;
    }
}
int main() {
    int num;
    int weight[5] = {0};
    vector<OpenSource> result;
    cin >> num;
    cin.ignore();
    for (int i = 0; i < 5; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < num; i++) {
        OpenSource temp;
        cin >> temp.name >> temp.watch >> temp.star >> temp.fork >> temp.issue >> temp.mr;
        transform(temp.name.begin(), temp.name.end(), temp.nameSmall.begin(), ::tolower);
        temp.sum = temp.watch * weight[0] + temp.star * weight[1] + temp.fork * weight[2] + temp.issue * weight[3] + temp.mr * weight[4];
        result.push_back(temp);
    }
    sort(result.begin(), result.end(), compare);
    for ( auto i : result) {
        cout << i.name << endl;
    }
    return 0;
}