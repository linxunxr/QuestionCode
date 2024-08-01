/**
 * Copyright (C), 2024-07-20
 * @author LinXun
 * @date 24-7-20 上午11:02
 * @version 1.0
 * @description: ${DESCRIPTION}
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> lengthSet;
    int rightIndex = 0;
    int leftIndex = 0;
    int result = 0;
    for (leftIndex; leftIndex < s.size() - result; ++leftIndex) {
        if (leftIndex != 0) {
            lengthSet.erase(s[leftIndex - 1]);
        }
        while (rightIndex < s.size() && !lengthSet.count(s[rightIndex])) {
            lengthSet.insert(s[rightIndex]);
            rightIndex++;
        }
        result = max(result, rightIndex - leftIndex);
    }
    return result;
}

int main() {
    string str = "pwwkew";
    cout << lengthOfLongestSubstring(str) <<  endl;
}