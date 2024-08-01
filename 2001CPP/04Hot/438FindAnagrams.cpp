/**
 * Copyright (C), 2024-07-20
 * @author LinXun
 * @date 24-7-20 上午11:13
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.size() < p.size()) {
        return result;
    }
    vector<int> pCount(26);
    vector<int> sCount(26);
    for (int i = 0; i < p.size(); ++i) {
        sCount[s[i] - 'a']++;
        pCount[p[i] - 'a']++;
    }
    if (sCount == pCount) {
        result.push_back(0);
    }
    for (int i = 0; i < s.size() - p.size(); ++i) {
        sCount[s[i] - 'a']--;
        sCount[s[i + p.size()] - 'a']++;
        if (sCount == pCount) {
            result.push_back(i + 1);
        }
    }
    return result;
}
int main() {
    string str = "aa";
    string target = "bb";
    vector<int> result = findAnagrams(str, target);
    for (int i : result) {
        cout << i << " ";
    }
}