/**
 * Copyright (C), 2024-07-21
 * @author LinXun
 * @date 24-7-21 下午7:22
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


bool checkInclusion(string s1, string s2) {
    int length = s1.size();
    if (length > s2.length()) {
        return false;
    }
    if (length == s2.length()) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2) {
            return true;
        } else {
            return false;
        }
    }
    sort(s1.begin(), s1.end());
    for (int i = 0; i < s2.size() - length; ++i) {
        string temp;
        for (int j = i; j < i + length; ++j) {
            temp.push_back(s2[j]);
        }
        sort(temp.begin(), temp.end());
        if (s1 == temp) {
            return true;
        }
    }
    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << checkInclusion(s1, s2) << endl;
    string s3 = "eidboaoo";
    cout << checkInclusion(s1, s3) << endl;
}